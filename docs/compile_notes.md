## Compile notes

Requires:
- Microsoft Detours 4.0.1 Express Library
- MFC 4.2 libraries (from Visual Studio 6.0 or another source - included)
- Microsoft Visual C++ 2010 Express
- modified MathPresso libraries (included)
- AsmJit 1.0 beta 4

Configuration Properties --> C/C++ --> General --> Additional Include Directories
- This needs to point to the MFC42 INCLUDE directory
- The easiest way to do this is to place the MFC42 directory into the TobEx directory

Configuration Properties --> Linker --> General --> Additional Library Directories
- This needs to point to the detours lib directory, the MFC42 lib directory, and the AsmJit directory
- The easiest way to do this is to place both the detours and MFC42 directories into the TobEx directory, and to place compiled AsmJit libraries into the TobEx\AsmJit directory
