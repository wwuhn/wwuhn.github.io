echo 正在清除F:\*.opt……
del /f /s /q F:\*.opt
echo 成功清除IDE的Option文件，工程关于开发环境的参数文件，如工具条位置等信息，保存工作空间的配置 。F:\*.opt！

echo 正在清除F:\*.ncb……
del /f /s /q F:\*.ncb
echo 成功清除.ncb文件记录了类的提示信息，如果类的成员函数和变量的提示不见了，重新生成该文件即可F:\*.ncb！

echo 正在清除F:\*.plg……
del /f /s /q F:\*.plg
echo 成功清除建立日志文件，是编译信息文件，编译时的error和warning信息文件F:\*.plg！

echo 正在清除F:\*.pch……
del /f /s /q F:\*.pch
echo 成功清除预编译头文件F:\*.pch！

echo 正在清除F:\*.res……
del /f /s /q F:\*.res
echo 成功清除VC++中编译好的资源文件(二进制) F:\*.res！

echo 正在清除F:\*.ilk……
del /f /s /q F:\*.ilk
echo 成功清除ILK：连接过程中生成的一种中间文件，只供LINK工具使用F:\*.ilk！
echo.

echo 正在清除F:\*.pdb……
del /f /s /q F:\*.pdb
echo 成功清除Program Database，记录了程序有关的一些数据和调试信息，在调试的时候可能有用。F:\*.pdb！

echo 正在清除F:\*.obj……
del /f /s /q F:\*.obj
echo 成功清除obj。F:\*.obj！

echo 正在清除F:\*.idb……
del /f /s /q F:\*.idb
echo 成功清除.idb记录了哪些文件是修改过的，需要重新编译的。。F:\*.idb！

echo 正在清除F:\*.tlh……
del /f /s /q F:\*.tlh
echo 成功清除tlh、tli文件：他们是VC++编译器解析 tlb 文件生成的标准 C++ 文件。F:\*.tlh！

echo 正在清除F:\*.tli……
del /f /s /q F:\*.tli
echo 成功清除tlh、tli文件：他们是VC++编译器解析 tlb 文件生成的标准 C++ 文件。F:\*.tli！
del /f /s /q F:\*.sdf

echo.
echo 垃圾文件已经清理完毕！

pause

rem DEL /F /A /Q //?/%1
rem RD /S /Q //?/%1