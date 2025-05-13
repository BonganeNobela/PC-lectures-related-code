#!/bin/bash

# Download and install Microsoft MPI (manual install required after download)
echo "Downloading Microsoft MPI installer..."
powershell.exe -Command "Invoke-WebRequest -Uri 'https://github.com/microsoft/Microsoft-MPI/releases/download/v10.1.1/msmpisetup.exe' -OutFile 'msmpisetup.exe'"
echo "Please run msmpisetup.exe manually to complete the installation."

# Download MinGW-w64 installer (manual install required after download)
echo "Downloading MinGW-w64 installer..."
powershell.exe -Command "Invoke-WebRequest -Uri 'https://sourceforge.net/projects/mingw-w64/files/latest/download' -OutFile 'mingw-w64.exe'"
echo "Please run mingw-w64.exe manually to complete the installation."

# Export Microsoft MPI bin directory to PATH for this session
export PATH="/c/Program Files/Microsoft MPI/Bin:$PATH"

# Export MinGW-w64 bin directory to PATH for this session (adjust if installed elsewhere)
export PATH="/c/mingw-w64/bin:$PATH"

# Export Windows Kits include directories (adjust version if needed)
export INCLUDE="/c/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/ucrt;/c/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/shared;$INCLUDE"

echo "Setup complete. If you installed MinGW-w64 or Windows Kits to a different directory or version, update the PATH and INCLUDE above."