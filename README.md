```text
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
██ ▄▄▄ █▀▄▄▀█ ██ █ ▄▄▀█▀▄▀█ ▄▄██ ▄▄▀█▀▄▄▀█ █ 
██▄▄▄▀▀█ ██ █ ██ █ ▀▀▄█ █▀█ ▄▄██ ▄▄▀█ ██ █▀▄▀
██ ▀▀▀ ██▄▄███▄▄▄█▄█▄▄██▄██▄▄▄██ ▀▀ ██▄▄██▄█▄
▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀

```

A Source-Container Simulation Environment

Developed in GEANT4 by **Kamaha Labs** at the _University of California, Los Angeles_

#### Installation 💽

Requirements:

+ [x] Geant4 v11.0.3 (v11)
+ [x] Cmake 3.24.2 or later
+ [x] Visualizer _e.g. Qt5_
+ [x] Analysis Tool _e.g. ROOT7_

#### Running the Program 🖥️

Instructions for Ubuntu (Bash):

1. Navigate Terminal to _.../AetherBones/Build_ Folder
2. **Source** Geant4 (Use your _geant4_ directory):

```bash
source /usr/local/geant4/11.0.2/bin/geant4.sh
```

3. **Build** using Cmake:

```bash
cmake ..
```

4. **Compile**:

```bash
make
```

5. Launch Aether (With or without a Macro):

```bash
./AetherBones SomeMacro.mac
```

#### Included Macros ⚙️

These Macros pertain to the **radioactive source** stored in the safe:

#### Container Materials and Dimensions 🎛️

See _AetherBones/**Construction.cc**_ and refer to comments.



