# dllmods-loader
Loads the **.dll files** located in **dllmods** folder near executable

Currently available entrypoints (x86 and x64):
* DINPUT8
* WINHTTP

Dll proxy files generated using [ProxiFy](https://www.codeproject.com/Articles/1179147/ProxiFy-Automatic-Proxy-DLL-Generation)

# Usage
Place the appropriate **entrypoint .dll** file near the **game's .exe** file
> To figure out which **entrypoint .dll** your game needs, you can use the **Dependency Walker** tool

Create the **dllmods** folder in the same location and place **your mod .dll** files inside it
