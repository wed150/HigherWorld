#include "mod/HigherWorld.h"
#include "ll/api/memory/Hook.h"
#include "ll/api/mod/RegisterHelper.h"
#include "ll/api/service/GamingStatus.h"
#include "mc/network/MinecraftPackets.h"
#include "mc/network/NetworkIdentifier.h"
#include "mc/network/ServerNetworkHandler.h"
#include "mc/network/packet/DimensionDataPacket.h"
#include "mc/network/Packet.h"
#include "mc/server/PropertiesSettings.h"
#include "mc/server/ServerPlayer.h"
#include "mc/world/level/dimension/Dimension.h"
#include "mc/world/level/dimension/DimensionDefinitionGroup.h"
#include "mc/world/level/dimension/DimensionHeightRange.h"
#include "mc/world/level/dimension/DerivedDimensionArguments.h"
#include "mc/world/level/dimension/DimensionArguments.h"
#include "mc/deps/core/utility/AutomaticID.h"
#include "mc/world/level/dimension/VanillaDimensions.h"

namespace glacie_team {

HigherWorld& HigherWorld::getInstance() {
    static HigherWorld instance;
    return instance;
}

bool HigherWorld::load() { return true; }

bool HigherWorld::enable() {
    auto& logger = getSelf().getLogger();
    logger.info("HigherWorld loaded!");
    logger.info("Overworld Max Height is now 512!");
    logger.info("Repository: https://github.com/GlacieTeam/HigherWorld");
    return true;
}

bool HigherWorld::disable() {
    if (ll::getGamingStatus() != ll::GamingStatus::Stopping) {
        getSelf().getLogger().error("The server is not stopped and HigherWorld cannot be disabled");
        return false;
    }
    return true;
}

} // namespace glacie_team

LL_REGISTER_MOD(glacie_team::HigherWorld, glacie_team::HigherWorld::getInstance());

LL_AUTO_TYPE_INSTANCE_HOOK(
    DimensionConstructor,
    ll::memory::HookPriority::Normal,
    Dimension,
    &Dimension::$ctor,
    void*,
    DimensionArguments&& args
) {
    if (args.mDimId == VanillaDimensions::Overworld()) {
        args.mHeightRange->mMax = 512;
    }
    return origin(std::forward<DimensionArguments>(args));
}

LL_AUTO_TYPE_INSTANCE_HOOK(
    PacketSend,
    HookPriority::Normal,
    ServerNetworkHandler,
    &ServerNetworkHandler::_sendLevelData,
    void,
    ServerPlayer&            newPlayer,
    const NetworkIdentifier& source
) {
    auto defPkt = std::static_pointer_cast<DimensionDataPacket>(
        MinecraftPackets::createPacket(MinecraftPacketIds::DimensionDataPacket)
    );
    defPkt->mDimensionDefinitionGroup->mDimensionDefinitions.get()["minecraft:overworld"] =
        DimensionDefinitionGroup::DimensionDefinition(-64, 512, GeneratorType::Void);
    defPkt->sendTo(newPlayer);
    return origin(newPlayer, source);
};

// Disable client side generation
LL_AUTO_TYPE_INSTANCE_HOOK(
    ClientGen,
    ll::memory::HookPriority::Normal,
    PropertiesSettings,
    &PropertiesSettings::$ctor,
    void*,
    const std::string& filename
) {
    auto result                          = (PropertiesSettings*)origin(filename);
    result->mClientSideGenerationEnabled = false;
    return result;
}