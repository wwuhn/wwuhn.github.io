Option Explicit
Dim objWMIService
Set objWMIService = GetObject("winmgmts:\\.\root\cimv2")
Dim objStartupInfo
Set objStartupInfo = objWMIService.Get("Win32_ProcessStartup")
objStartupInfo.SpawnInstance_
objStartupInfo.X = 0
objStartupInfo.XSize = 200
objStartupInfo.Y = 0
objStartupInfo.YSize = 200
Dim objNewProcess
Set objNewProcess = objWMIService.Get("Win32_Process")
Dim intPID
Dim errRtn
errRtn = objNewProcess.Create("cmd.exe", Null, objStartupInfo, intPID)