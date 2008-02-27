# sdcc.nsi - NSIS installer script for SDCC
#
# Copyright (c) 2003-2008 Borut Razem
#
# This file is part of sdcc.
#
#  This software is provided 'as-is', without any express or implied
#  warranty.  In no event will the authors be held liable for any damages
#  arising from the use of this software.
#
#  Permission is granted to anyone to use this software for any purpose,
#  including commercial applications, and to alter it and redistribute it
#  freely, subject to the following restrictions:
#
#  1. The origin of this software must not be misrepresented; you must not
#     claim that you wrote the original software. If you use this software
#     in a product, an acknowledgment in the product documentation would be
#     appreciated but is not required.
#  2. Altered source versions must be plainly marked as such, and must not be
#     misrepresented as being the original software.
#  3. This notice may not be removed or altered from any source distribution.
#
#  Borut Razem
#  borut.razem@siol.net

# How to create WIN32 setup.exe
#
# - unpack WIN32 mingw daily snapshot sdcc-snapshot-i586-mingw32msvc-yyyymmdd-rrrr.zip
#   to a clean directory (the option to create directories should be enabled).
#   A sub directory sdcc is created (referenced as PKGDIR in continuation).
# - copy files sdcc/support/scripts/sdcc.ico and sdcc/support/scripts/sdcc.nsi
#   (this file) from the sdcc Subversion snapshot to the PKGDIR directory
# - copy file COPYING from the sdcc Subversion snapshot to the PKGDIR directory,
#   rename it to COPYING.TXT and convert it to DOS format:
#   unix2dos COPYING.TXT
# - copy readline5.dll to PKGDIR/bin/readline5.dll
# - run NSIS installer from PKGDIR directory:
#   "c:\Program Files\NSIS\makensis.exe" -DVER_MAJOR=<SDCC_VER_MAJOR> -DVER_MINOR=<SDCC_VER_MINOR> -DVER_REVISION=<SDCC_VER_DEVEL> -DVER_BUILD=<SDCC_REVISION> sdcc.nsi
#   replace <VER_XXX> with the appropriate values, for example for SDCC 2.7.4:
#   <SDCC_VER_MAJOR> = 2
#   <SDCC_VER_MINOR> = 7
#   <SDCC_VER_DEVEL> = 4
#   replace <SDCC_REVISION> with the current svn revision number
# - A setup file setup.exe is created in PKGDIR directory.
#   Rename it to sdcc-yyyymmdd-rrrr-setup.exe and upload it
#   to sdcc download repository at sourceforge.net
#
#
# How to create WIN32 release setup.exe package
#
# - unpack WIN32 mingw daily snapshot sdcc-snapshot-i586-mingw32msvc-yyyymmdd-rrrr.zip
#   to a clean directory (the option to create directories should be enabled).
#   A sub directory sdcc is created (referenced as PKGDIR in continuation).
# - remove the PKGDIR/doc/README.TXT file
# - unpack sdcc-doc-yyyymmdd-rrrr.zip to the PKGDIR/doc directory
# - copy files sdcc/support/scripts/sdcc.ico and sdcc/support/scripts/sdcc.nsi
#   (this file) from the sdcc Subversion snapshot to the PKGDIR directory
# - copy file COPYING from the sdcc Subversion snapshot to the PKGDIR directory,
#   rename it to COPYING.TXT and it to DOS format:
#   unix2dos COPYING.TXT
# - copy readline5.dll to PKGDIR/bin/readline5.dll
# - run NSIS installer from PKGDIR directory:
#   "c:\Program Files\NSIS\makensis.exe" -DFULL_DOC -DVER_MAJOR=<VER_MAJOR> -DVER_MINOR=<VER_MINOR> -DVER_REVISION=<VER_PATCH> -DVER_BUILD=<REVISION> sdcc.nsi
# - A setup file setup.exe is created in PKGDIR directory.
#   Rename it to sdcc-x.x.x-setup.exe and upload it
#   to sdcc download repository at sourceforge.net
#
# How to upload secc setup.exe tosourceforge.net
#
# Execute following commands from the cmd prompt:
# - sftp sdcc.sourceforge.net
# - cd /home/groups/s/sd/sdcc/htdocs/snapshots/i586-mingw32msvc-setup
# - put sdcc_yyyymmdd_setup.exe
# - quit


!define PRODUCT_NAME "SDCC"

; Version
!ifdef VER_MAJOR & VER_MINOR & VER_REVISION & VER_BUILD
  !define PRODUCT_VERSION "${VER_MAJOR}.${VER_MINOR}.${VER_REVISION}"
!else
  !define PRODUCT_VERSION "XX.XX"
!endif

SetCompressor /SOLID lzma

!define SDCC_ROOT "."

!define DEV_ROOT "${SDCC_ROOT}"

!system "unix2dos ${SDCC_ROOT}\doc\ChangeLog_head.txt" = 0
!system "unix2dos ${SDCC_ROOT}\doc\README.TXT" = 0

InstType "Full (Bin, ucSim, SDCDB, Doc, Lib, Src)"
InstType "Medium (Bin, ucSim, SDCDB, Doc, Lib)"
InstType "Compact (Bin, ucSim, SDCDB, Doc)"

;--------------------------------
; Header Files

!define MULTIUSER_INSTALLMODE_INSTDIR SDCC
!define MULTIUSER_EXECUTIONLEVEL Highest
!define MULTIUSER_MUI
!define MULTIUSER_INSTALLMODE_COMMANDLINE
!include MultiUser.nsh
!include MUI2.nsh
!include WordFunc.nsh

;--------------------------------
; Functions

!ifdef VER_MAJOR & VER_MINOR & VER_REVISION & VER_BUILD
  !insertmacro VersionCompare
!endif

;--------------------------------
; Configuration

!define PRODUCT_UNINST_KEY "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}"

;--------------------------------
; Configuration

; MUI Settings
!define MUI_ABORTWARNING

; Welcome page
!insertmacro MUI_PAGE_WELCOME

; License page
!insertmacro MUI_PAGE_LICENSE "${SDCC_ROOT}\COPYING.TXT"

; Uninstall/reinstall page
!ifdef VER_MAJOR & VER_MINOR & VER_REVISION & VER_BUILD
Page custom PageReinstall PageLeaveReinstall
!endif

; MultiUser page
!insertmacro MULTIUSER_PAGE_INSTALLMODE

; StartMenu page
!define MUI_STARTMENUPAGE_DEFAULTFOLDER ${PRODUCT_NAME}
!define MUI_STARTMENUPAGE_REGISTRY_ROOT "HKLM"
!define MUI_STARTMENUPAGE_REGISTRY_KEY ${PRODUCT_UNINST_KEY}
!define MUI_STARTMENUPAGE_REGISTRY_VALUENAME "NSIS:StartMenuDir"
!define MUI_STARTMENUPAGE_NODISABLE
Var MUI_STARTMENUPAGE_VARIABLE
!insertmacro MUI_PAGE_STARTMENU Application $MUI_STARTMENUPAGE_VARIABLE

; Components page
!define MUI_COMPONENTSPAGE_SMALLDESC
!insertmacro MUI_PAGE_COMPONENTS

; Directory page
!insertmacro MUI_PAGE_DIRECTORY

; Instfiles page
!insertmacro MUI_PAGE_INSTFILES

; Finish page
!define MUI_FINISHPAGE_SHOWREADME_TEXT "Add $INSTDIR\bin to the PATH"
!define MUI_FINISHPAGE_SHOWREADME_FUNCTION AddBinToPath
!define MUI_FINISHPAGE_SHOWREADME
!insertmacro MUI_PAGE_FINISH

; Uninstaller pages
!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES

; Language files
!insertmacro MUI_LANGUAGE "English"

Name "${PRODUCT_NAME} ${PRODUCT_VERSION}"
BrandingText ""
OutFile "setup.exe"
;;;;ShowInstDetails show
;;;;ShowUnInstDetails show

Function .onInit
!ifndef VER_MAJOR & VER_MINOR & VER_REVISION & VER_BUILD
  ; Old unistallation method
  ;Uninstall the old version, if present
  ReadRegStr $R0 HKLM \
  "Software\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" \
  "UninstallString"
  StrCmp $R0 "" inst

  MessageBox MB_OKCANCEL|MB_ICONEXCLAMATION \
  "$(^Name) is already installed. $\n$\nClick 'OK' to remove the \
  previous version or 'Cancel' to cancel this upgrade." \
  IDOK uninst
  Abort

uninst:
  ; Run the uninstaller
  ClearErrors
  ExecWait '$R0 _?=$INSTDIR' ;Do not copy the uninstaller to a temp file

  Goto done
inst:

  ; Install the new version
  MessageBox MB_YESNO|MB_ICONQUESTION "This will install $(^Name). Do you wish to continue?" IDYES +2
  Abort

done:
!endif
  !insertmacro MULTIUSER_INIT
FunctionEnd

Function un.onInit
  !insertmacro MULTIUSER_UNINIT
FunctionEnd

Section -Common
  SetOutPath "$INSTDIR"
  File ".\sdcc.ico"
  File "${SDCC_ROOT}\COPYING.TXT"
SectionEnd

Section "SDCC application files" SEC01
  SectionIn 1 2 3 RO
  SetOutPath "$INSTDIR\bin"
  File "${SDCC_ROOT}\bin\as-gbz80.exe"
  File "${SDCC_ROOT}\bin\as-hc08.exe"
  File "${SDCC_ROOT}\bin\as-z80.exe"
  File "${SDCC_ROOT}\bin\asx8051.exe"
  File "${SDCC_ROOT}\bin\aslink.exe"
  File "${SDCC_ROOT}\bin\link-gbz80.exe"
  File "${SDCC_ROOT}\bin\link-hc08.exe"
  File "${SDCC_ROOT}\bin\link-z80.exe"
  File "${SDCC_ROOT}\bin\makebin.exe"
  File "${SDCC_ROOT}\bin\packihx.exe"
  File "${SDCC_ROOT}\bin\sdcc.exe"
  File "${SDCC_ROOT}\bin\sdcclib.exe"
  File "${SDCC_ROOT}\bin\sdcpp.exe"
  File "${SDCC_ROOT}\bin\readline5.dll"
SectionEnd

Section "ucSim application files" SEC02
  SectionIn 1 2 3
  SetOutPath "$INSTDIR\bin"
  File "${SDCC_ROOT}\bin\s51.exe"
  File "${SDCC_ROOT}\bin\savr.exe"
  File "${SDCC_ROOT}\bin\shc08.exe"
  File "${SDCC_ROOT}\bin\sz80.exe"
SectionEnd

Section "SDCDB files" SEC03
  SectionIn 1 2 3
  File "${SDCC_ROOT}\bin\sdcdb.exe"
  File "${SDCC_ROOT}\bin\sdcdb.el"
  File "${SDCC_ROOT}\bin\sdcdbsrc.el"
SectionEnd

Section "SDCC documentation" SEC04
  SectionIn 1 2 3
  SetOutPath "$INSTDIR\doc"
!ifdef FULL_DOC
  File /r "${SDCC_ROOT}\doc\*"
!else
  File "${SDCC_ROOT}\doc\ChangeLog_head.txt"
  File "${SDCC_ROOT}\doc\README.TXT"
!endif
SectionEnd

Section "SDCC include files" SEC05
  SectionIn 1 2
  SetOutPath "$INSTDIR\include\asm\default"
  File "${DEV_ROOT}\include\asm\default\features.h"
  SetOutPath "$INSTDIR\include\asm\ds390"
  File "${DEV_ROOT}\include\asm\ds390\features.h"
  SetOutPath "$INSTDIR\include\asm\gbz80"
  File "${DEV_ROOT}\include\asm\gbz80\features.h"
  SetOutPath "$INSTDIR\include\asm\mcs51"
  File "${DEV_ROOT}\include\asm\mcs51\features.h"
  SetOutPath "$INSTDIR\include\asm\pic"
  File "${DEV_ROOT}\include\asm\pic\features.h"
  SetOutPath "$INSTDIR\include\asm\pic16"
  File "${DEV_ROOT}\include\asm\pic16\features.h"
  SetOutPath "$INSTDIR\include\asm\z80"
  File "${DEV_ROOT}\include\asm\z80\features.h"
  SetOutPath "$INSTDIR\include\hc08"
  File "${DEV_ROOT}\include\hc08\*.h"
  SetOutPath "$INSTDIR\include\mcs51"
  File "${DEV_ROOT}\include\mcs51\*.h"
  SetOutPath "$INSTDIR\include\pic"
  File "${DEV_ROOT}\include\pic\*.h"
  File "${DEV_ROOT}\include\pic\*.txt"
  File "${DEV_ROOT}\include\pic\*.inc"
  SetOutPath "$INSTDIR\include\pic16"
  File "${DEV_ROOT}\include\pic16\*.h"
  SetOutPath "$INSTDIR\include\z80"
  File "${DEV_ROOT}\include\z80\*.h"
  SetOutPath "$INSTDIR\include"
  File "${DEV_ROOT}\include\*.h"
SectionEnd

Section "SDCC DS390 library" SEC06
  SectionIn 1 2
  SetOutPath "$INSTDIR\lib\ds390"
  File "${DEV_ROOT}\lib\ds390\*.rel"
  File "${DEV_ROOT}\lib\ds390\*.lib"
SectionEnd

Section "SDCC DS400 library" SEC07
  SectionIn 1 2
  SetOutPath "$INSTDIR\lib\ds400"
  File "${DEV_ROOT}\lib\ds400\*.rel"
  File "${DEV_ROOT}\lib\ds400\*.lib"
SectionEnd

Section "SDCC GBZ80 library" SEC08
  SectionIn 1 2
  SetOutPath "$INSTDIR\lib\gbz80"
  File "${DEV_ROOT}\lib\gbz80\*.o"
  File "${DEV_ROOT}\lib\gbz80\*.lib"
SectionEnd

Section "SDCC Z80 library" SEC09
  SectionIn 1 2
  SetOutPath "$INSTDIR\lib\z80"
  File "${DEV_ROOT}\lib\z80\*.o"
  File "${DEV_ROOT}\lib\z80\*.lib"
SectionEnd

Section "SDCC small model library" SEC10
  SectionIn 1 2
  SetOutPath "$INSTDIR\lib\small"
  File "${DEV_ROOT}\lib\small\*.rel"
  File "${DEV_ROOT}\lib\small\*.lib"
SectionEnd

Section "SDCC medium model library" SEC11
  SectionIn 1 2
  SetOutPath "$INSTDIR\lib\medium"
  File "${DEV_ROOT}\lib\medium\*.rel"
  File "${DEV_ROOT}\lib\medium\*.lib"
SectionEnd

Section "SDCC large model library" SEC12
  SectionIn 1 2
  SetOutPath "$INSTDIR\lib\large"
  File "${DEV_ROOT}\lib\large\*.rel"
  File "${DEV_ROOT}\lib\large\*.lib"
SectionEnd

Section "SDCC small-stack-auto model library" SEC13
  SectionIn 1 2
  SetOutPath "$INSTDIR\lib\small-stack-auto"
  File "${DEV_ROOT}\lib\small-stack-auto\*.rel"
  File "${DEV_ROOT}\lib\small-stack-auto\*.lib"
SectionEnd

Section "SDCC HC08 library" SEC14
  SectionIn 1 2
  SetOutPath "$INSTDIR\lib\hc08"
  File "${DEV_ROOT}\lib\hc08\*.rel"
  File "${DEV_ROOT}\lib\hc08\*.lib"
SectionEnd

Section "SDCC PIC16 library" SEC15
  SectionIn 1 2
  SetOutPath "$INSTDIR\lib\pic16"
  File "${DEV_ROOT}\lib\pic16\*.o"
  File "${DEV_ROOT}\lib\pic16\*.lib"
SectionEnd

Section "SDCC PIC library" SEC16
  SectionIn 1 2
  SetOutPath "$INSTDIR\lib\pic"
  File "${DEV_ROOT}\lib\pic\*.lib"
SectionEnd

Section "SDCC library sources" SEC17
  SectionIn 1
  SetOutPath "$INSTDIR\lib\src\ds390\examples"
  File "${DEV_ROOT}\lib\src\ds390\examples\MOVED"

  SetOutPath "$INSTDIR\lib\src\ds390"
  File "${DEV_ROOT}\lib\src\ds390\*.c"
#  File "${DEV_ROOT}\lib\src\ds390\Makefile"

  SetOutPath "$INSTDIR\lib\src\ds400"
  File "${DEV_ROOT}\lib\src\ds400\*.c"
#  File "${DEV_ROOT}\lib\src\ds400\Makefile"

  SetOutPath "$INSTDIR\lib\src\gbz80"
  File "${DEV_ROOT}\lib\src\gbz80\*.c"
  File "${DEV_ROOT}\lib\src\gbz80\*.s"
#  File "${DEV_ROOT}\lib\src\gbz80\Makefile"

  SetOutPath "$INSTDIR\lib\src\z80"
  File "${DEV_ROOT}\lib\src\z80\*.c"
  File "${DEV_ROOT}\lib\src\z80\*.s"
#  File "${DEV_ROOT}\lib\src\z80\Makefile"

  SetOutPath "$INSTDIR\lib\src\hc08"
  File "${DEV_ROOT}\lib\src\hc08\*.c"
#  File "${DEV_ROOT}\lib\src\hc08\Makefile"

  SetOutPath "$INSTDIR\lib\src\mcs51"
  File "${DEV_ROOT}\lib\src\mcs51\*.asm"
#  File "${DEV_ROOT}\lib\src\mcs51\Makefile"

  SetOutPath "$INSTDIR\lib\src\small"
#  File "${DEV_ROOT}\lib\src\small\Makefile"

  SetOutPath "$INSTDIR\lib\src\medium"
#  File "${DEV_ROOT}\lib\src\medium\Makefile"

  SetOutPath "$INSTDIR\lib\src\large"
#  File "${DEV_ROOT}\lib\src\large\Makefile"

  SetOutPath "$INSTDIR\lib\src\pic"
#  File "${DEV_ROOT}\lib\src\pic\configure"
#  File "${DEV_ROOT}\lib\src\pic\configure.in"
#  File "${DEV_ROOT}\lib\src\pic\GPL"
#  File "${DEV_ROOT}\lib\src\pic\LGPL"
#  File "${DEV_ROOT}\lib\src\pic\Makefile"
#  File "${DEV_ROOT}\lib\src\pic\Makefile.common"
#  File "${DEV_ROOT}\lib\src\pic\Makefile.common.in"
#  File "${DEV_ROOT}\lib\src\pic\Makefile.rules"
#  File "${DEV_ROOT}\lib\src\pic\Makefile.subdir"
#  File "${DEV_ROOT}\lib\src\pic\NEWS"
#  File "${DEV_ROOT}\lib\src\pic\README"
  File "${DEV_ROOT}\lib\src\pic\TEMPLATE.c"
  File "${DEV_ROOT}\lib\src\pic\TEMPLATE.S"

  SetOutPath "$INSTDIR\lib\src\pic\libsdcc"
  File "${DEV_ROOT}\lib\src\pic\libsdcc\*.c"
  File "${DEV_ROOT}\lib\src\pic\libsdcc\*.S"
  File "${DEV_ROOT}\lib\src\pic\libsdcc\*.inc"
#  File "${DEV_ROOT}\lib\src\pic\libsdcc\Makefile"
  
  SetOutPath "$INSTDIR\lib\src\pic\libdev"
  File "${DEV_ROOT}\lib\src\pic\libdev\*.c"
#  File "${DEV_ROOT}\lib\src\pic\libdev\Makefile"

  SetOutPath "$INSTDIR\lib\src\pic\libm"
  File "${DEV_ROOT}\lib\src\pic\libm\*.c"

  SetOutPath "$INSTDIR\lib\src\pic16"
#  File "${DEV_ROOT}\lib\src\pic16\configure"
#  File "${DEV_ROOT}\lib\src\pic16\configure.in"
#  File "${DEV_ROOT}\lib\src\pic16\COPYING"
#  File "${DEV_ROOT}\lib\src\pic16\Makefile"
#  File "${DEV_ROOT}\lib\src\pic16\Makefile.common"
#  File "${DEV_ROOT}\lib\src\pic16\Makefile.common.in"
#  File "${DEV_ROOT}\lib\src\pic16\Makefile.rules"
#  File "${DEV_ROOT}\lib\src\pic16\Makefile.subdir"
#  File "${DEV_ROOT}\lib\src\pic16\pics.all"
#  File "${DEV_ROOT}\lib\src\pic16\pics.build"
#  File "${DEV_ROOT}\lib\src\pic16\README"

  SetOutPath "$INSTDIR\lib\src\pic16\debug"
#  File "${DEV_ROOT}\lib\src\pic16\debug\Makefile"

  SetOutPath "$INSTDIR\lib\src\pic16\debug\gstack"
#  File "${DEV_ROOT}\lib\src\pic16\debug\gstack\Makefile"
  File "${DEV_ROOT}\lib\src\pic16\debug\gstack\*.c"

  SetOutPath "$INSTDIR\lib\src\pic16\libc"
#  File "${DEV_ROOT}\lib\src\pic16\libc\Makefile"

  SetOutPath "$INSTDIR\lib\src\pic16\libc\ctype"
  File "${DEV_ROOT}\lib\src\pic16\libc\ctype\*.c"
#  File "${DEV_ROOT}\lib\src\pic16\libc\ctype\Makefile"

  SetOutPath "$INSTDIR\lib\src\pic16\libc\delay"
  File "${DEV_ROOT}\lib\src\pic16\libc\delay\*.S"
#  File "${DEV_ROOT}\lib\src\pic16\libc\delay\Makefile"

  SetOutPath "$INSTDIR\lib\src\pic16\libc\stdio"
  File "${DEV_ROOT}\lib\src\pic16\libc\stdio\*.c"
#  File "${DEV_ROOT}\lib\src\pic16\libc\stdio\Makefile"

  SetOutPath "$INSTDIR\lib\src\pic16\libc\stdlib"
  File "${DEV_ROOT}\lib\src\pic16\libc\stdlib\*.c"
  File "${DEV_ROOT}\lib\src\pic16\libc\stdlib\*.S"
#  File "${DEV_ROOT}\lib\src\pic16\libc\stdlib\Makefile"

  SetOutPath "$INSTDIR\lib\src\pic16\libc\string"
  File "${DEV_ROOT}\lib\src\pic16\libc\string\*.c"
#  File "${DEV_ROOT}\lib\src\pic16\libc\string\Makefile"

  SetOutPath "$INSTDIR\lib\src\pic16\libc\utils"
  File "${DEV_ROOT}\lib\src\pic16\libc\utils\*.S"
#  File "${DEV_ROOT}\lib\src\pic16\libc\utils\Makefile"

  SetOutPath "$INSTDIR\lib\src\pic16\libdev"
  File "${DEV_ROOT}\lib\src\pic16\libdev\*.c"
#  File "${DEV_ROOT}\lib\src\pic16\libdev\Makefile"

  SetOutPath "$INSTDIR\lib\src\pic16\libio"
  File "${DEV_ROOT}\lib\src\pic16\libio\*.ignore"
#  File "${DEV_ROOT}\lib\src\pic16\libio\Makefile"

  SetOutPath "$INSTDIR\lib\src\pic16\libio\adc"
  File "${DEV_ROOT}\lib\src\pic16\libio\adc\*.c"
#  File "${DEV_ROOT}\lib\src\pic16\libio\adc\Makefile"

  SetOutPath "$INSTDIR\lib\src\pic16\libio\i2c"
  File "${DEV_ROOT}\lib\src\pic16\libio\i2c\*.c"
#  File "${DEV_ROOT}\lib\src\pic16\libio\i2c\Makefile"

  SetOutPath "$INSTDIR\lib\src\pic16\libio\usart"
  File "${DEV_ROOT}\lib\src\pic16\libio\usart\*.c"
#  File "${DEV_ROOT}\lib\src\pic16\libio\usart\Makefile"

  SetOutPath "$INSTDIR\lib\src\pic16\libm"
  File "${DEV_ROOT}\lib\src\pic16\libm\*.c"
#  File "${DEV_ROOT}\lib\src\pic16\libm\Makefile"

  SetOutPath "$INSTDIR\lib\src\pic16\libsdcc"
#  File "${DEV_ROOT}\lib\src\pic16\libsdcc\Makefile"

  SetOutPath "$INSTDIR\lib\src\pic16\libsdcc\char"
  File "${DEV_ROOT}\lib\src\pic16\libsdcc\char\*.c"
#  File "${DEV_ROOT}\lib\src\pic16\libsdcc\char\Makefile"

  SetOutPath "$INSTDIR\lib\src\pic16\libsdcc\fixed16x16"
  File "${DEV_ROOT}\lib\src\pic16\libsdcc\fixed16x16\*.c"
  File "${DEV_ROOT}\lib\src\pic16\libsdcc\fixed16x16\*.S"
#  File "${DEV_ROOT}\lib\src\pic16\libsdcc\fixed16x16\Makefile"

  SetOutPath "$INSTDIR\lib\src\pic16\libsdcc\float"
  File "${DEV_ROOT}\lib\src\pic16\libsdcc\float\*.c"
#  File "${DEV_ROOT}\lib\src\pic16\libsdcc\float\Makefile"

  SetOutPath "$INSTDIR\lib\src\pic16\libsdcc\gptr"
  File "${DEV_ROOT}\lib\src\pic16\libsdcc\gptr\*.c"
#  File "${DEV_ROOT}\lib\src\pic16\libsdcc\gptr\Makefile"

  SetOutPath "$INSTDIR\lib\src\pic16\libsdcc\int"
  File "${DEV_ROOT}\lib\src\pic16\libsdcc\int\*.c"
#  File "${DEV_ROOT}\lib\src\pic16\libsdcc\int\Makefile"

  SetOutPath "$INSTDIR\lib\src\pic16\libsdcc\long"
  File "${DEV_ROOT}\lib\src\pic16\libsdcc\long\*.c"
#  File "${DEV_ROOT}\lib\src\pic16\libsdcc\long\Makefile"

  SetOutPath "$INSTDIR\lib\src\pic16\libsdcc\lregs"
  File "${DEV_ROOT}\lib\src\pic16\libsdcc\lregs\*.c"
#  File "${DEV_ROOT}\lib\src\pic16\libsdcc\lregs\Makefile"

  SetOutPath "$INSTDIR\lib\src\pic16\libsdcc\stack"
  File "${DEV_ROOT}\lib\src\pic16\libsdcc\stack\*.S"

  SetOutPath "$INSTDIR\lib\src\pic16\startup"
  File "${DEV_ROOT}\lib\src\pic16\startup\*.c"
#  File "${DEV_ROOT}\lib\src\pic16\startup\Makefile"
#  File "${DEV_ROOT}\lib\src\pic16\startup\README"

  SetOutPath "$INSTDIR\lib\src"
  File "${DEV_ROOT}\lib\src\*.c"
SectionEnd

;--------------------------------
;Descriptions

;Language strings
LangString DESC_SEC01 ${LANG_ENGLISH} "SDCC application files"
LangString DESC_SEC02 ${LANG_ENGLISH} "ucSim application files"
LangString DESC_SEC03 ${LANG_ENGLISH} "SDCDB files"
LangString DESC_SEC04 ${LANG_ENGLISH} "SDCC documentation"
LangString DESC_SEC05 ${LANG_ENGLISH} "SDCC include files"
LangString DESC_SEC06 ${LANG_ENGLISH} "SDCC DS390 library"
LangString DESC_SEC07 ${LANG_ENGLISH} "SDCC DS400 library"
LangString DESC_SEC08 ${LANG_ENGLISH} "SDCC GBZ80 library"
LangString DESC_SEC09 ${LANG_ENGLISH} "SDCC Z80 library"
LangString DESC_SEC10 ${LANG_ENGLISH} "SDCC small model library"
LangString DESC_SEC11 ${LANG_ENGLISH} "SDCC medium model library"
LangString DESC_SEC12 ${LANG_ENGLISH} "SDCC large model library"
LangString DESC_SEC13 ${LANG_ENGLISH} "SDCC small-stack-auto model library"
LangString DESC_SEC14 ${LANG_ENGLISH} "SDCC HC08 library"
LangString DESC_SEC15 ${LANG_ENGLISH} "SDCC PIC16 library"
LangString DESC_SEC16 ${LANG_ENGLISH} "SDCC PIC library"
LangString DESC_SEC17 ${LANG_ENGLISH} "SDCC library sources"

;Assign language strings to sections
!insertmacro MUI_FUNCTION_DESCRIPTION_BEGIN
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC01} $(DESC_SEC01)
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC02} $(DESC_SEC02)
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC03} $(DESC_SEC03)
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC04} $(DESC_SEC04)
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC05} $(DESC_SEC05)
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC06} $(DESC_SEC06)
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC07} $(DESC_SEC07)
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC08} $(DESC_SEC08)
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC09} $(DESC_SEC09)
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC10} $(DESC_SEC10)
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC11} $(DESC_SEC11)
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC12} $(DESC_SEC12)
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC13} $(DESC_SEC13)
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC14} $(DESC_SEC14)
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC15} $(DESC_SEC15)
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC16} $(DESC_SEC16)
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC17} $(DESC_SEC17)
!insertmacro MUI_FUNCTION_DESCRIPTION_END
;--------------------------------

Section -Icons
!insertmacro MUI_STARTMENU_WRITE_BEGIN Application
  CreateDirectory "$SMPROGRAMS\$MUI_STARTMENUPAGE_VARIABLE"
  CreateShortCut "$SMPROGRAMS\$MUI_STARTMENUPAGE_VARIABLE\SDCC on the Web.lnk" "$INSTDIR\sdcc.url" 
  CreateShortCut "$SMPROGRAMS\$MUI_STARTMENUPAGE_VARIABLE\Uninstall SDCC.lnk" "$INSTDIR\uninstall.exe" 
  CreateShortCut "$SMPROGRAMS\$MUI_STARTMENUPAGE_VARIABLE\Documentation.lnk" "$INSTDIR\doc\README.TXT" "" "$INSTDIR\sdcc.ico" "" "" "" ""
  CreateShortCut "$SMPROGRAMS\$MUI_STARTMENUPAGE_VARIABLE\Change Log.lnk" "$INSTDIR\doc\ChangeLog_head.txt" "" "$INSTDIR\sdcc.ico" "" "" "" ""
  CreateShortCut "$SMPROGRAMS\$MUI_STARTMENUPAGE_VARIABLE\GPL 2 License.lnk" "$INSTDIR\COPYING.TXT" 
!insertmacro MUI_STARTMENU_WRITE_END
SectionEnd

Section -INI
  WriteIniStr "$INSTDIR\sdcc.url" "InternetShortcut" "URL" "http://sdcc.sourceforge.net/"
SectionEnd

Section -PostInstall
  WriteRegStr HKLM "Software\${PRODUCT_NAME}" "" $INSTDIR
!ifdef VER_MAJOR & VER_MINOR & VER_REVISION & VER_BUILD
  WriteRegDword HKLM "Software\${PRODUCT_NAME}" "VersionMajor" "${VER_MAJOR}"
  WriteRegDword HKLM "Software\${PRODUCT_NAME}" "VersionMinor" "${VER_MINOR}"
  WriteRegDword HKLM "Software\${PRODUCT_NAME}" "VersionRevision" "${VER_REVISION}"
  WriteRegDword HKLM "Software\${PRODUCT_NAME}" "VersionBuild" "${VER_BUILD}"
!endif

  WriteRegStr HKLM ${PRODUCT_UNINST_KEY} "DisplayName" "${PRODUCT_NAME}"
  WriteRegStr HKLM ${PRODUCT_UNINST_KEY} "UninstallString" "$INSTDIR\uninstall.exe"
  WriteRegStr HKLM ${PRODUCT_UNINST_KEY} "Publisher" "sdcc.sourceforge.net"
  WriteRegStr HKLM ${PRODUCT_UNINST_KEY} "URLInfoAbout" "http://sdcc.sourceforge.net/"
  WriteRegStr HKLM ${PRODUCT_UNINST_KEY} "HelpLink" "http://sdcc.sourceforge.net/"
  WriteRegStr HKLM ${PRODUCT_UNINST_KEY} "URLUpdateInfo" "http://sdcc.sourceforge.net/"

  WriteUninstaller "$INSTDIR\uninstall.exe"
SectionEnd


;;;; Uninstaller code ;;;;

Section Uninstall
  !insertmacro MUI_STARTMENU_GETFOLDER Application $MUI_STARTMENUPAGE_VARIABLE

  Delete "$SMPROGRAMS\$MUI_STARTMENUPAGE_VARIABLE\GPL 2 License.lnk"
  Delete "$SMPROGRAMS\$MUI_STARTMENUPAGE_VARIABLE\Change Log.lnk"
  Delete "$SMPROGRAMS\$MUI_STARTMENUPAGE_VARIABLE\Documentation.lnk"
  Delete "$SMPROGRAMS\$MUI_STARTMENUPAGE_VARIABLE\Uninstall SDCC.lnk"
  Delete "$SMPROGRAMS\$MUI_STARTMENUPAGE_VARIABLE\SDCC on the Web.lnk"

  RMDir "$SMPROGRAMS\$MUI_STARTMENUPAGE_VARIABLE"

  Delete "$INSTDIR\lib\src\large\Makefile"

  Delete "$INSTDIR\lib\src\medium\Makefile"

  Delete "$INSTDIR\lib\src\small\Makefile"

  Delete "$INSTDIR\lib\src\mcs51\*.asm"
  Delete "$INSTDIR\lib\src\mcs51\Makefile"
  Delete "$INSTDIR\lib\src\mcs51\README"

  Delete "$INSTDIR\lib\src\hc08\*.c"
  Delete "$INSTDIR\lib\src\hc08\hc08.lib"
  Delete "$INSTDIR\lib\src\hc08\Makefile"

  Delete "$INSTDIR\lib\src\z80\*.c"
  Delete "$INSTDIR\lib\src\z80\*.s"
  Delete "$INSTDIR\lib\src\z80\z80.lib"
  Delete "$INSTDIR\lib\src\z80\README"
  Delete "$INSTDIR\lib\src\z80\Makefile"

  Delete "$INSTDIR\lib\src\gbz80\*.c"
  Delete "$INSTDIR\lib\src\gbz80\*.s"
  Delete "$INSTDIR\lib\src\gbz80\gbz80.lib"
  Delete "$INSTDIR\lib\src\gbz80\README"
  Delete "$INSTDIR\lib\src\gbz80\Makefile"

  Delete "$INSTDIR\lib\src\ds390\*.c"
  Delete "$INSTDIR\lib\src\ds390\libds390.lib"
  Delete "$INSTDIR\lib\src\ds390\Makefile.dep"
  Delete "$INSTDIR\lib\src\ds390\Makefile"
  Delete "$INSTDIR\lib\src\ds390\examples\MOVED"

  Delete "$INSTDIR\lib\src\ds400\*.c"
  Delete "$INSTDIR\lib\src\ds400\libds400.lib"
  Delete "$INSTDIR\lib\src\ds400\Makefile.dep"
  Delete "$INSTDIR\lib\src\ds400\Makefile"

  Delete "$INSTDIR\lib\src\*.c"

  Delete "$INSTDIR\lib\pic\*.o"
  Delete "$INSTDIR\lib\pic\*.lib"

  Delete "$INSTDIR\lib\pic16\*.o"
  Delete "$INSTDIR\lib\pic16\*.lib"

  Delete "$INSTDIR\lib\hc08\*.rel"
  Delete "$INSTDIR\lib\hc08\*.lib"

  Delete "$INSTDIR\lib\z80\*.o"
  Delete "$INSTDIR\lib\z80\*.lib"

  Delete "$INSTDIR\lib\small\*.rel"
  Delete "$INSTDIR\lib\small\*.lib"

  Delete "$INSTDIR\lib\medium\*.rel"
  Delete "$INSTDIR\lib\medium\*.lib"

  Delete "$INSTDIR\lib\large\*.rel"
  Delete "$INSTDIR\lib\large\*.lib"

  Delete "$INSTDIR\lib\small-stack-auto\*.rel"
  Delete "$INSTDIR\lib\small-stack-auto\*.lib"

  Delete "$INSTDIR\lib\gbz80\*.o"
  Delete "$INSTDIR\lib\gbz80\*.lib"

  Delete "$INSTDIR\lib\ds390\*.rel"
  Delete "$INSTDIR\lib\ds390\*.lib"

  Delete "$INSTDIR\lib\ds400\*.rel"
  Delete "$INSTDIR\lib\ds400\*.lib"

  Delete "$INSTDIR\include\asm\z80\*.h"
  Delete "$INSTDIR\include\asm\pic16\*.h"
  Delete "$INSTDIR\include\asm\pic\*.h"
  Delete "$INSTDIR\include\asm\mcs51\*.h"
  Delete "$INSTDIR\include\asm\gbz80\*.h"
  Delete "$INSTDIR\include\asm\ds390\*.h"
  Delete "$INSTDIR\include\asm\default\*.h"
  Delete "$INSTDIR\include\z80\*.h"
  Delete "$INSTDIR\include\pic\*.h"
  Delete "$INSTDIR\include\pic\*.txt"
  Delete "$INSTDIR\include\pic\*.inc"
  Delete "$INSTDIR\include\pic16\*.h"
  Delete "$INSTDIR\include\mcs51\*.h"
  Delete "$INSTDIR\include\hc08\*.h"
  Delete "$INSTDIR\include\*.h"

!ifndef FULL_DOC
  Delete "$INSTDIR\doc\README.TXT"
  Delete "$INSTDIR\doc\ChangeLog_head.txt"
!endif

  Delete "$INSTDIR\bin\as-gbz80.exe"
  Delete "$INSTDIR\bin\as-hc08.exe"
  Delete "$INSTDIR\bin\as-z80.exe"
  Delete "$INSTDIR\bin\asx8051.exe"
  Delete "$INSTDIR\bin\aslink.exe"
  Delete "$INSTDIR\bin\link-gbz80.exe"
  Delete "$INSTDIR\bin\link-hc08.exe"
  Delete "$INSTDIR\bin\link-z80.exe"
  Delete "$INSTDIR\bin\makebin.exe"
  Delete "$INSTDIR\bin\packihx.exe"
  Delete "$INSTDIR\bin\sdcc.exe"
  Delete "$INSTDIR\bin\sdcclib.exe"
  Delete "$INSTDIR\bin\sdcpp.exe"
  Delete "$INSTDIR\bin\readline5.dll"


  Delete "$INSTDIR\bin\s51.exe"
  Delete "$INSTDIR\bin\savr.exe"
  Delete "$INSTDIR\bin\shc08.exe"
  Delete "$INSTDIR\bin\sz80.exe"

  Delete "$INSTDIR\bin\sdcdb.exe"
  Delete "$INSTDIR\bin\sdcdb.el"
  Delete "$INSTDIR\bin\sdcdbsrc.el"

  Delete "$INSTDIR\COPYING.TXT"
  Delete "$INSTDIR\sdcc.ico"
  Delete "$INSTDIR\sdcc.url"
  Delete "$INSTDIR\uninstall.exe"

  RMDir /r "$INSTDIR\lib\src\pic"
  RMDir /r "$INSTDIR\lib\src\pic16"
  RMDir "$INSTDIR\lib\src\small"
  RMDir "$INSTDIR\lib\src\medium"
  RMDir "$INSTDIR\lib\src\large"
  RMDir "$INSTDIR\lib\src\mcs51"
  RMDir "$INSTDIR\lib\src\z80"
  RMDir "$INSTDIR\lib\src\gbz80"
  RMDir "$INSTDIR\lib\src\ds390\examples"
  RMDir "$INSTDIR\lib\src\ds390"
  RMDir "$INSTDIR\lib\src\ds400"
  RMDir "$INSTDIR\lib\src\hc08"
  RMDir "$INSTDIR\lib\src"

  RMDir "$INSTDIR\lib\pic"
  RMDir "$INSTDIR\lib\pic16"
  RMDir "$INSTDIR\lib\z80"
  RMDir "$INSTDIR\lib\small"
  RMDir "$INSTDIR\lib\medium"
  RMDir "$INSTDIR\lib\large"
  RMDir "$INSTDIR\lib\small-stack-auto"
  RMDir "$INSTDIR\lib\gbz80"
  RMDir "$INSTDIR\lib\ds390"
  RMDir "$INSTDIR\lib\ds400"
  RMDir "$INSTDIR\lib\hc08"
  RMDir "$INSTDIR\lib"

  RMDir "$INSTDIR\include\asm\z80"
  RMDir "$INSTDIR\include\asm\pic16"
  RMDir "$INSTDIR\include\asm\pic"
  RMDir "$INSTDIR\include\asm\mcs51"
  RMDir "$INSTDIR\include\asm\gbz80"
  RMDir "$INSTDIR\include\asm\ds390"
  RMDir "$INSTDIR\include\asm\default"
  RMDir "$INSTDIR\include\asm"
  RMDir "$INSTDIR\include\z80"
  RMDir "$INSTDIR\include\pic"
  RMDir "$INSTDIR\include\pic16"
  RMDir "$INSTDIR\include\mcs51"
  RMDir "$INSTDIR\include\hc08"
  RMDir "$INSTDIR\include"

!ifdef FULL_DOC
  RMDir /r "$INSTDIR\doc"
!else
  RMDir "$INSTDIR\doc"
!endif

  RMDir "$INSTDIR\bin"

  RMDir "$INSTDIR"

  Push "$INSTDIR\bin"
  Call un.RemoveFromPath

; Clean the registry
  DeleteRegValue HKLM ${PRODUCT_UNINST_KEY} "NSIS:StartMenuDir"
  DeleteRegKey HKLM "${PRODUCT_UNINST_KEY}"
  DeleteRegKey HKLM "Software\${PRODUCT_NAME}"
;;;;  SetAutoClose true
SectionEnd

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Path Manipulation functions                                                 ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

!verbose 3
!include "WinMessages.nsh"
!verbose 4

Function AddBinToPath
    Push "$INSTDIR\bin"
    Call AddToPath
FunctionEnd

; AddToPath - Adds the given dir to the search path.
;        Input - head of the stack
;        Note - Win9x systems requires reboot

Function AddToPath
  Exch $0
  Push $1
  Push $2
  Push $3
  Push $4

  ; don't add if the path doesn't exist
  IfFileExists $0 "" AddToPath_done

  Call IsNT
  Pop $4
  StrCmp $4 1 +3
    ; Not on NT: read PATH from environment variable
    ReadEnvStr $1 PATH
    Goto +2
    ; On NT: read PATH from registry
    ReadRegStr $1 HKCU "Environment" "PATH"
  ${StrStr} $2 "$1;" "$0;"
  StrCmp $2 "" "" AddToPath_done

  ${StrStr} $2 "$1;" "$0\;"
  StrCmp $2 "" "" AddToPath_done

  GetFullPathName /SHORT $3 $0
  ${StrStr} $2 "$1;" "$3;"
  StrCmp $2 "" "" AddToPath_done

  ${StrStr} $2 "$1;" "$03\;"
  StrCmp $2 "" "" AddToPath_done

  StrCmp $4 1 AddToPath_NT
    ; Not on NT
    StrCpy $1 $WINDIR 2
    FileOpen $1 "$1\autoexec.bat" a
    FileSeek $1 -1 END
    FileReadByte $1 $2
    IntCmp $2 26 0 +2 +2 ; DOS EOF
      FileSeek $1 -1 END ; write over EOF
    FileWrite $1 "$\r$\nSET PATH=%PATH%;$3$\r$\n"
    FileClose $1
    SetRebootFlag true
    Goto AddToPath_done

  AddToPath_NT:
    ;System PATH variable is at:
    ;HKLM "/SYSTEM/CurrentControlSet/Control/Session Manager/Environment" "Path"
    ReadRegStr $1 HKCU "Environment" "PATH"
    StrCpy $2 $1 1 -1  ; copy last char
    StrCmp $2 ";" 0 +2 ; if last char == ;
      StrCpy $1 $1 -1  ; remove last char
    StrCmp $1 "" AddToPath_NTdoIt
      StrCpy $0 "$1;$0"
    AddToPath_NTdoIt:
      WriteRegExpandStr HKCU "Environment" "PATH" $0
      SendMessage ${HWND_BROADCAST} ${WM_WININICHANGE} 0 "STR:Environment" /TIMEOUT=5000

  AddToPath_done:
    Pop $4
    Pop $3
    Pop $2
    Pop $1
    Pop $0
FunctionEnd

; RemoveFromPath - Remove a given dir from the path
;     Input: head of the stack

Function un.RemoveFromPath
  Exch $0
  Push $1
  Push $2
  Push $3
  Push $4
  Push $5
  Push $6

  IntFmt $6 "%c" 26 ; DOS EOF

  Call un.IsNT
  Pop $1
  StrCmp $1 1 unRemoveFromPath_NT
    ; Not on NT
    StrCpy $1 $WINDIR 2
    FileOpen $1 "$1\autoexec.bat" r
    GetTempFileName $4
    FileOpen $2 $4 w
    GetFullPathName /SHORT $0 $0
    StrCpy $0 "SET PATH=%PATH%;$0"
    Goto unRemoveFromPath_dosLoop

    unRemoveFromPath_dosLoop:
      FileRead $1 $3
      StrCpy $5 $3 1 -1 ; read last char
      StrCmp $5 $6 0 +2 ; if DOS EOF
        StrCpy $3 $3 -1 ; remove DOS EOF so we can compare
      StrCmp $3 "$0$\r$\n" unRemoveFromPath_dosLoopRemoveLine
      StrCmp $3 "$0$\n" unRemoveFromPath_dosLoopRemoveLine
      StrCmp $3 "$0" unRemoveFromPath_dosLoopRemoveLine
      StrCmp $3 "" unRemoveFromPath_dosLoopEnd
      FileWrite $2 $3
      Goto unRemoveFromPath_dosLoop
      unRemoveFromPath_dosLoopRemoveLine:
        SetRebootFlag true
        Goto unRemoveFromPath_dosLoop

    unRemoveFromPath_dosLoopEnd:
      FileClose $2
      FileClose $1
      StrCpy $1 $WINDIR 2
      Delete "$1\autoexec.bat"
      CopyFiles /SILENT $4 "$1\autoexec.bat"
      Delete $4
      Goto unRemoveFromPath_done

  unRemoveFromPath_NT:
    ;System PATH variable is at:
    ;HKLM "/SYSTEM/CurrentControlSet/Control/Session Manager/Environment" "Path"
    ReadRegStr $1 HKCU "Environment" "PATH"
    StrCpy $5 $1 1 -1 ; copy last char
    StrCmp $5 ";" +2  ; if last char != ;
      StrCpy $1 "$1;" ; append ;
    ${UnStrStr} $2 $1 "$0;"	; Find `$0;` in $1
    StrCmp $2 "" unRemoveFromPath_done
      ; else, it is in path
      ; $0 - path to add
      ; $1 - path var
      StrLen $3 "$0;"
      StrLen $4 $2
      StrCpy $5 $1 -$4   ; $5 is now the part before the path to remove
      StrCpy $6 $2 "" $3 ; $6 is now the part after the path to remove
      StrCpy $3 $5$6

      StrCpy $5 $3 1 -1  ; copy last char
      StrCmp $5 ";" 0 +2 ; if last char == ;
        StrCpy $3 $3 -1  ; remove last char

      StrCmp $3 "" +3
        ; New PATH not empty: update the registry
        WriteRegExpandStr HKCU "Environment" "PATH" $3
        Goto +2
        ; New PATH empty: remove from the registry
        DeleteRegValue HKCU "Environment" "PATH"
      SendMessage ${HWND_BROADCAST} ${WM_WININICHANGE} 0 "STR:Environment" /TIMEOUT=5000

  unRemoveFromPath_done:
    Pop $6
    Pop $5
    Pop $4
    Pop $3
    Pop $2
    Pop $1
    Pop $0
FunctionEnd

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Utility Functions                                                           ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; IsNT
; no input
; output, top of the stack = 1 if NT or 0 if not
;
; Usage:
;   Call IsNT
;   Pop $R0
;  ($R0 at this point is 1 or 0)

!macro IsNT un
Function ${un}IsNT
  Push $0
  ReadRegStr $0 HKLM "SOFTWARE\Microsoft\Windows NT\CurrentVersion" CurrentVersion
  StrCmp $0 "" 0 IsNT_yes
  ; we are not NT.
  Pop $0
  Push 0
  Return

  IsNT_yes:
    ; NT!!!
    Pop $0
    Push 1
FunctionEnd
!macroend
!insertmacro IsNT ""
!insertmacro IsNT "un."

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  Uninstall/Reinstall page functions                                         ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

!ifdef VER_MAJOR & VER_MINOR & VER_REVISION & VER_BUILD

Var ReinstallPageCheck

Function PageReinstall

  ReadRegStr $R0 HKLM "Software\${PRODUCT_NAME}" ""

  ${If} $R0 == ""
    ReadRegStr $R0 HKLM "${PRODUCT_UNINST_KEY}" "UninstallString"
    ${If} $R0 == ""
      Abort
    ${EndIf}
  ${EndIf}

  ReadRegDWORD $R0 HKLM "Software\${PRODUCT_NAME}" "VersionMajor"
  ReadRegDWORD $R1 HKLM "Software\${PRODUCT_NAME}" "VersionMinor"
  ReadRegDWORD $R2 HKLM "Software\${PRODUCT_NAME}" "VersionRevision"
  ReadRegDWORD $R3 HKLM "Software\${PRODUCT_NAME}" "VersionBuild"
  StrCpy $R0 $R0.$R1.$R2.$R3

  ${VersionCompare} ${VER_MAJOR}.${VER_MINOR}.${VER_REVISION}.${VER_BUILD} $R0 $R0
  ${If} $R0 == 0
    StrCpy $R1 "${PRODUCT_NAME} ${PRODUCT_VERSION} is already installed. Select the operation you want to perform and click Next to continue."
    StrCpy $R2 "Add/Reinstall components"
    StrCpy $R3 "Uninstall ${PRODUCT_NAME}"
    !insertmacro MUI_HEADER_TEXT "Already Installed" "Choose the maintenance option to perform."
    StrCpy $R0 "2"
  ${ElseIf} $R0 == 1
    StrCpy $R1 "An older version of ${PRODUCT_NAME} is installed on your system. It's recommended that you uninstall the current version before installing. Select the operation you want to perform and click Next to continue."
    StrCpy $R2 "Uninstall before installing"
    StrCpy $R3 "Do not uninstall"
    !insertmacro MUI_HEADER_TEXT "Already Installed" "Choose how you want to install ${PRODUCT_NAME}."
    StrCpy $R0 "1"
  ${ElseIf} $R0 == 2
    StrCpy $R1 "A newer version of ${PRODUCT_NAME} is already installed! It is not recommended that you install an older version. If you really want to install this older version, it's better to uninstall the current version first. Select the operation you want to perform and click Next to continue."
    StrCpy $R2 "Uninstall before installing"
    StrCpy $R3 "Do not uninstall"
    !insertmacro MUI_HEADER_TEXT "Already Installed" "Choose how you want to install ${PRODUCT_NAME}."
    StrCpy $R0 "1"
  ${Else}
    Abort
  ${EndIf}

  nsDialogs::Create /NOUNLOAD 1018

  ${NSD_CreateLabel} 0 0 100% 24u $R1
  Pop $R1

  ${NSD_CreateRadioButton} 30u 50u -30u 8u $R2
  Pop $R2
  ${NSD_OnClick} $R2 PageReinstallUpdateSelection

  ${NSD_CreateRadioButton} 30u 70u -30u 8u $R3
  Pop $R3
  ${NSD_OnClick} $R3 PageReinstallUpdateSelection

  ${If} $ReinstallPageCheck != 2
    SendMessage $R2 ${BM_SETCHECK} ${BST_CHECKED} 0
  ${Else}
    SendMessage $R3 ${BM_SETCHECK} ${BST_CHECKED} 0
  ${EndIf}

  nsDialogs::Show

FunctionEnd

Function PageReinstallUpdateSelection

  Pop $R1

  ${NSD_GetState} $R2 $R1

  ${If} $R1 == ${BST_CHECKED}
    StrCpy $ReinstallPageCheck 1
  ${Else}
    StrCpy $ReinstallPageCheck 2
  ${EndIf}

FunctionEnd

Function PageLeaveReinstall

  ${NSD_GetState} $R2 $R1

  StrCmp $R0 "1" 0 +2
    StrCmp $R1 "1" reinst_uninstall reinst_done

  StrCmp $R0 "2" 0 +3
    StrCmp $R1 "1" reinst_done reinst_uninstall

  reinst_uninstall:
  ReadRegStr $R1 HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}" "UninstallString"

  ;Run uninstaller
  HideWindow

    ClearErrors
    ExecWait '$R1 _?=$INSTDIR'

    IfErrors no_remove_uninstaller
    IfFileExists "$INSTDIR\bin\${PRODUCT_NAME}.exe" no_remove_uninstaller

      Delete $R1
      RMDir $INSTDIR

    no_remove_uninstaller:

  StrCmp $R0 "2" 0 +2
    Quit

  BringToFront

  reinst_done:

FunctionEnd

!endif # VER_MAJOR & VER_MINOR & VER_REVISION & VER_BUILD
