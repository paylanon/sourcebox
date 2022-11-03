```text
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
██ ▄▄▄ █▀▄▄▀█ ██ █ ▄▄▀█▀▄▀█ ▄▄██ ▄▄▀█▀▄▄▀█ █ 
██▄▄▄▀▀█ ██ █ ██ █ ▀▀▄█ █▀█ ▄▄██ ▄▄▀█ ██ █▀▄▀
██ ▀▀▀ ██▄▄███▄▄▄█▄█▄▄██▄██▄▄▄██ ▀▀ ██▄▄██▄█▄
▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀

```

A Source-Container Simulation Environment

Developed in GEANT4 by **Kamaha Labs** at UCLA

### Installation 💽

Requirements:

+ [x] Geant4 v11.0.3 (v11)
+ [x] Cmake 3.24.2 or later
+ [x] Visualizer _e.g. Qt5_
+ [x] Analysis Tool _e.g. ROOT7_

#### Installing _Geant4_ in Ubuntu 22:

Start by opening a **Terminal** window.

First, install dependencies:

```bash
sudo apt install -y qt5-default
sudo apt install -y libxerces-c-dev

sudo apt install -y gfortran
sudo apt install -y python3-dev python3-numpy-dev

sudo apt install -y libxpm-dev libxft-dev libxmu-dev
sudo apt install -y libssl-dev

sudo apt-get install -y libpcre3-dev xlibmesa-glu-dev \
                   libglew1.5-dev libftgl-dev libfftw3-dev libcfitsio-dev \
                   graphviz-dev libxml2-dev libgsl0-dev

sudo apt install -y libfreetype6-dev
```
For those not found, the Terminal should suggest replacements: install those.

Follow by **Upgrading System**, as you always should before any installation:

```bash
sudo apt update
sudo apt upgrade
```

Install _build-essential_ and _cmake_:

```bash
sudo apt install -y build-essential
sudo install -y cmake
```

Clone _Geant4_ from it's Git repository:

```bash
git clone https://gitlab.cern.ch/geant4/geant4.git
cd geant4/
```

Create a directory on your system for _Geant4_, ideally including a version number:

```bash
sudo mkdir -p /usr/local/geant4/11.x.x
sudo chown -R 'YourUsername' /usr/local/geant4
```

Now we compile and install:

```bash
mkdir geant4-build
cd geant4-build
cmake  -DCMAKE_INSTALL_PREFIX=/usr/local/geant4/11.x.x \
  -DCMAKE_BUILD_TYPE=RelWithDebInfo [ -DGEANT4_BUILD_MULTITHREADED=ON ] \
  -DGEANT4_INSTALL_DATA=ON -DGEANT4_USE_GDML=ON -DGEANT4_USE_QT=ON \
  -DGEANT4_USE_OPENGL_X11=ON [-DGEANT4_USE_FREETYPE=ON] ../geant4
```

```bash
cmake --build . --target install -- -j4
```
Donzo, _Geant4_ is now ready for action.

#### Installing _ROOT_:

Download the latest version of ROOT, as a **TAR** file, from the following link: https://root.cern/install/all_releases/

Move the TAR file from **Downloads** to **your root folder**, then unpack and install:

```bash
sudo tar zxf root_vx.xx.x.Linux-ubuntu22.tar.gz -C /usr/local/
sudo chown -R 'YourUsername' /usr/local/root
chmod +x /usr/local/root/bin/thisroot.*
```

### Running SourceBox 🖥️

Instructions for Ubuntu:

1. Navigate Terminal to _.../SourceBox/Build_ Folder
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
./SourceBox SomeMacro.mac
```

To use ROOT7 for analysis:

1. **Source** ROOT:

```bash
source /usr/local/root/bin/thisroot.sh
```

2. Run ROOT **with the Output.root file**:

```bash
root Output.root
```

### Included Macros ⚙️

These macros pertain to the **radioactive source** stored in the safe:

> Cf252

> AmBe

Create your own macros by copying these files, and replacing the **energy spectrum** with that of your source.

### Container Materials and Dimensions 🎛️

The included geometry is a steel safe with two inner layers of HDPE, a container used at Kamaha Labs.

```text
 ___________
|   _____   |
|  |  _  |  |
|  | |_| |  |
|  |_____|  |
|___________|

...you get the idea.
```

To make changes to the geometry, see _SourceBox/**Construction.cc**_ and refer to comments.

