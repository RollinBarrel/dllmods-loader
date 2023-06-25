# dllmods-loader
Loads the **.dll files** located in **dllmods** folder near executable

Currently available entrypoints (x86 and x64):
* DINPUT8 ([x86](https://github.com/RollinBarrel/dllmods-loader/releases/download/1.0-86/dinput8.dll)/[x64](https://github.com/RollinBarrel/dllmods-loader/releases/download/1.0/dinput8.dll))
* WINHTTP ([x86](https://github.com/RollinBarrel/dllmods-loader/releases/download/1.0-86/winhttp.dll)/[x64](https://github.com/RollinBarrel/dllmods-loader/releases/download/1.0/winhttp.dll))

Dll proxy files generated using [ProxiFy](https://www.codeproject.com/Articles/1179147/ProxiFy-Automatic-Proxy-DLL-Generation)

# Usage
Place the appropriate **entrypoint .dll** file near the **game's .exe** file
> To figure out which **entrypoint .dll** your game needs, you can use the **Dependency Walker** tool

Create the **dllmods** folder in the same location and place **your mod .dll** files inside it
