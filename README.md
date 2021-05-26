# **riscvOVPsimPlus Setup and Demo in Windows**

This is a guide on how to setup and run your RISC-V Vector-based program with riscvOVPsimPlus in your Windows devices. There are folders such as `imperas-riscv-tests` and `riscv-toolchains` which we didn't include in this repository due to its size. But, we provided a guide as to how you can obtain the two folders through the steps below.
<br /><br />

## **Turn on Windows Subsystem for Linux (Reboot might be required)**
![alt text](https://mafft.cbrc.jp/alignment/software/TurnWindowsFeaturesOnOrOff.png?raw=true)
## **Install Ubuntu from Microsoft Store**
Link: **https://www.microsoft.com/en-us/p/ubuntu/9nblggh4msv6**  
*Takes several minutes and then asks you to set a username and a password.*
## **Install Dependencies in Ubuntu Terminal**
```
sudo apt-get install gcc make
```
## **Clone the RISC-V  Toolchains Repository**
```
git clone https://github.com/Imperas/riscv-toolchains -b rvv-0.8.x
```
## **Edit Makefile (Optional)**

## **Add an environment variable in PATH**
This is used to compile your program. You will compile your program in **Ubuntu Terminal**.
```
path-to\riscv-toolchains\Linux64\sifive-riscv-none-gcc\bin
```
## **Download riscvOVPsimPlus**
Download the riscvOVPsimPlus with base and test suites from OVPWorld website. Please take note that you might need to register to be able to download the test suites. Once you can see the download page, choose the **riscvOVPsimPlus with base and example configuration V Vector test suites**.

Once the file is downloaded, you will get a zip file. Extract the content, and copy the `imperas-riscv-tests` folder to your project folder.

**Link: https://www.ovpworld.org/library/wikka.php?wakka=riscvOVPsimPlus**
<br /><br />

## **Project Folder Structure**
After copying the `imperas-riscv-tests` to your project folder, this is how the structure of your project folder should look like.
```
project folder
- imperas-riscv-tests
    - riscv-ovpsim-plus
    ...
- riscv-toolchains
    - Linux64
    ...
- compile.sh
- compile_vsupport.sh
- run.bat
- run.sh
- vsupport.c
- vsupport.h
- vtest.c
- windows-subsystem-for-linux.png
```

## **Add an environment variable in PATH**
This is used to run your program. You can opt to run it in **Linux (Ubuntu Terminal)** or **Windows (CMD)**, just **add one** of the paths below.
```
# For Linux
path-to\imperas-riscv-tests\riscv-ovpsim-plus\bin\Linux64
# For Windows
path-to\imperas-riscv-tests\riscv-ovpsim-plus\bin\Windows64
```

## **Compilation and Running**
* Compile `vsupport.c` by running `compile_vsupport.sh` in Ubuntu Terminal (*you only need to do this once*). This will generate for you the `vsupport.o` used to compile `vtest.c`.
* Compile `vtest.c` by running `compile.sh` in Ubuntu Terminal. This will generate for you the `vtest.elf` which is used to run your program.
* Run your program with `run.sh` in Ubuntu Terminal or `run.bat` in CMD.
<br /><br />
## **Files Description**
#### **`vtest.c`**
A sample C program to do a vector multiplication using the RISC-V Vector Extension.

#### **`vsupport.c` and `vsupport.h`**
Support files used for compilation and running your C program with RISC-V Vector Extension.
#### **`compile_vsupport.sh`**
This file is used to compile the `vsupport.c`.

#### **`compile.sh`**
This file is used to compile the `vtest.c`.

#### **`run.sh` and `run.bat`**
This file is used to run your program. Use `run.sh` if you want to run it in a **Linux (Ubuntu Terminal)**, and `run.bat` if you want to run in it **Windows (CMD)**.