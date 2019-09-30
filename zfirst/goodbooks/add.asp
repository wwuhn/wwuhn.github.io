<%@LANGUAGE="VBSCRIPT" CODEPAGE="936"%>
 
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
<title>add self</title>
</head>

<body>
<%
classify1 = trim(request.Form("classify"))
title1 = trim(request.Form("title"))
author1 = trim(request.Form("author"))
publisher1 = trim(request.Form("publisher"))
gt1 = trim(request.Form("gt"))
remark1 = trim(request.Form("remark"))
readdate1 = trim(request.Form("readdate"))

%>
<%
dim oCmd,oConn,db
set oConn = Server.CreateObject("ADODB.Connection")
set oCmd = Server.CreateObject("ADODB.command")
db = "\wwu.accdb"
oConn.ConnectionString="Provider=Microsoft.ACE.OLEDB.12.0;"&_
"Data Source=" & Server.MapPath(db)

oConn.open
Set oCmd.ActiveConnection = oConn
oCmd.CommandText = "INSERT INTO records (classify,title,author,publisher,gt,readdate,remark) VALUES ('"& classify1 &"','"& title1 &"','"& author1 &"','"& publisher1 &"','"& gt1 &"','"& readdate1 &"','"& remark1 &"')"
oCmd.Execute
Response.Write("操作成功！")

%>

<%
oConn.Close
Set oConn = Nothing
%>
<%
response.Redirect("admin.asp")
%>
</body>
</html>
<%
Recordset1.Close()
Set Recordset1 = Nothing
%>
