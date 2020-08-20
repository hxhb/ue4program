This is a Create UE StandaloneApplication tool.
### Usage

```bash
$ ue4program.exe $ProgramName
```
0. move $ProgramName Folder to Engine\Source\Programs (version of source code)
1. run GenerateProgramProject.bat
2. run OpenProgramProject.bat

![](https://imzlp.me/notes/index/UEStandaloneApplication.png)

### build

```bash
$ clang++ ue4program.cpp string_tools.cpp BaseProgramFile.cpp -o ue4program.exe -std=c++11
```
