# HigherWorld

[![Discord](https://img.shields.io/discord/1346034987136192523?style=for-the-badge&logo=discord)](https://discord.gg/7uJNS3tNa6)

[![Latest Tag](https://img.shields.io/github/v/tag/GlacieTeam/HigherWorld?label=Latest%20Tag&style=for-the-badge)](https://github.com/GlacieTeam/HigherWorld/releases)
[![Stars](https://img.shields.io/github/stars/GlacieTeam/HigherWorld.svg?style=for-the-badge)](https://github.com/GlacieTeam/HigherWorld/stargazers)  
[![Downloads](https://img.shields.io/github/downloads/GlacieTeam/HigherWorld/total?style=for-the-badge&color=%2300ff00)](https://github.com/GlacieTeam/HigherWorld/releases)
[![Issues](https://img.shields.io/github/issues/GlacieTeam/HigherWorld.svg?style=for-the-badge)](https://github.com/GlacieTeam/HigherWorld/issues)
<html>没有可行函数。<br/>实参类型: void *(Dimension::*)(DimensionArguments &amp;&amp;)。<br/>考虑的候选项:<br/>constexpr ll::memory::FuncPtr resolveIdentifier&lt;FuncPtrType T&gt;(T identifier) (namespace ll::memory 中)<br/>1st实参 &amp;Dimension::$ctor 的转换格式错误: 无法将void *(Dimension::*)(DimensionArguments &amp;&amp;)转换为形参类型 void *(Dimension::*)(DimensionArguments &amp;)，<br/>因为源函数和目标函数具有不同的1st形参类型: DimensionArguments &amp;&amp; 和 DimensionArguments &amp;<br/>constexpr ll::memory::FuncPtr resolveIdentifier&lt;T&gt;(ll::memory::SignatureView identifier) (namespace ll::memory 中)<br/>1st实参 &amp;Dimension::$ctor 的转换格式错误: 无法将类型 void *(Dimension::*)(DimensionArguments &amp;&amp;) 的右值转换为形参类型 ll::memory::SignatureView<br/>constexpr ll::memory::FuncPtr resolveIdentifier&lt;T&gt;(ll::memory::SymbolView identifier) (namespace ll::memory 中)<br/>1st实参 &amp;Dimension::$ctor 的转换格式错误: 无法将类型 void *(Dimension::*)(DimensionArguments &amp;&amp;) 的右值转换为形参类型 ll::memory::SymbolView<br/>constexpr ll::memory::FuncPtr resolveIdentifier&lt;T&gt;(uintptr_t address) (namespace ll::memory 中)<br/>1st实参 &amp;Dimension::$ctor 的转换格式错误: 无法将void *(Dimension::*)(DimensionArguments &amp;&amp;)转换为形参类型 uintptr_t
## Description
`HigherWorld` is a server-side mod built on the LeviLamina mod loader that changes the overworld max height to 512.  
No need to modify the client, as this mod has excellent compatibility.

## Installation

```bash
lip install github.com/GlacieTeam/HigherWorld
```

## Communication & FAQ
- Join our [Discord](https://discord.gg/7uJNS3tNa6) community: https://discord.gg/7uJNS3tNa6

## Feedback
- [Open an issue](https://github.com/GlacieTeam/HigherWorld/issues) to report bugs.

## License
Please note that this project is licensed under the [GPLv3](LICENSE).   
If you modify or distribute this project, you must comply with the requirements of the GPLv3 license, including but not limited to providing the complete source code and retaining the copyright notices. For more detailed information, please visit the GNU Official Website.

### Copyright © 2025 GlacieTeam. All rights reserved.
