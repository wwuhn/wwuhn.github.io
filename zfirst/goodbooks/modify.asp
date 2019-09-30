<%@LANGUAGE="VBSCRIPT" CODEPAGE="936"%>

<%
' *** Edit Operations: declare variables

Dim MM_editAction
Dim MM_abortEdit
Dim MM_editQuery
Dim MM_editCmd

Dim MM_editConnection
Dim MM_editTable
Dim MM_editRedirectUrl
Dim MM_editColumn
Dim MM_recordId

Dim MM_fieldsStr
Dim MM_columnsStr
Dim MM_fields
Dim MM_columns
Dim MM_typeArray
Dim MM_formVal
Dim MM_delim
Dim MM_altVal
Dim MM_emptyVal
Dim MM_i

dim oConn
dim db
set oConn = Server.CreateObject("ADODB.Connection")
db = "\wwu.accdb"
oConn.ConnectionString="Provider=Microsoft.ACE.OLEDB.12.0;"&_
"Data Source=" & Server.MapPath(db)

oConn.open()


MM_editAction = CStr(Request.ServerVariables("SCRIPT_NAME"))
If (Request.QueryString <> "") Then
  MM_editAction = MM_editAction & "?" & Server.HTMLEncode(Request.QueryString)
End If

' boolean to abort record edit
MM_abortEdit = false

' query string to execute
MM_editQuery = ""
%>
<%
' *** Update Record: set variables

If (CStr(Request("MM_update")) = "form1" And CStr(Request("MM_recordId")) <> "") Then

  MM_editConnection = oConn
  MM_editTable = "records"
  MM_editColumn = "id"
  MM_recordId = "" + Request.Form("MM_recordId") + ""
  MM_editRedirectUrl = "admin.asp"
  MM_fieldsStr  = "author|value|title|value|classify|value|publisher|value|gt|value|readdate|value|remark|value"
  MM_columnsStr = "author|',none,''|title|',none,''|classify|',none,''|publisher|',none,''|gt|',none,''|readdate|',none,''|remark|',none,''"

  ' create the MM_fields and MM_columns arrays
  MM_fields = Split(MM_fieldsStr, "|")
  MM_columns = Split(MM_columnsStr, "|")
  
  ' set the form values
  For MM_i = LBound(MM_fields) To UBound(MM_fields) Step 2
    MM_fields(MM_i+1) = CStr(Request.Form(MM_fields(MM_i)))
  Next

  ' append the query string to the redirect URL
  If (MM_editRedirectUrl <> "" And Request.QueryString <> "") Then
    If (InStr(1, MM_editRedirectUrl, "?", vbTextCompare) = 0 And Request.QueryString <> "") Then
      MM_editRedirectUrl = MM_editRedirectUrl & "?" & Request.QueryString
    Else
      MM_editRedirectUrl = MM_editRedirectUrl & "&" & Request.QueryString
    End If
  End If

End If
%>
<%
' *** Update Record: construct a sql update statement and execute it

If (CStr(Request("MM_update")) <> "" And CStr(Request("MM_recordId")) <> "") Then

  ' create the sql update statement
  MM_editQuery = "update " & MM_editTable & " set "
  For MM_i = LBound(MM_fields) To UBound(MM_fields) Step 2
    MM_formVal = MM_fields(MM_i+1)
    MM_typeArray = Split(MM_columns(MM_i+1),",")
    MM_delim = MM_typeArray(0)
    If (MM_delim = "none") Then MM_delim = ""
    MM_altVal = MM_typeArray(1)
    If (MM_altVal = "none") Then MM_altVal = ""
    MM_emptyVal = MM_typeArray(2)
    If (MM_emptyVal = "none") Then MM_emptyVal = ""
    If (MM_formVal = "") Then
      MM_formVal = MM_emptyVal
    Else
      If (MM_altVal <> "") Then
        MM_formVal = MM_altVal
      ElseIf (MM_delim = "'") Then  ' escape quotes
        MM_formVal = "'" & Replace(MM_formVal,"'","''") & "'"
      Else
        MM_formVal = MM_delim + MM_formVal + MM_delim
      End If
    End If
    If (MM_i <> LBound(MM_fields)) Then
      MM_editQuery = MM_editQuery & ","
    End If
    MM_editQuery = MM_editQuery & MM_columns(MM_i) & " = " & MM_formVal
  Next
  MM_editQuery = MM_editQuery & " where " & MM_editColumn & " = " & MM_recordId

  If (Not MM_abortEdit) Then
    ' execute the update
    Set MM_editCmd = Server.CreateObject("ADODB.Command")
    MM_editCmd.ActiveConnection = MM_editConnection
    MM_editCmd.CommandText = MM_editQuery
    MM_editCmd.Execute
    MM_editCmd.ActiveConnection.Close

    If (MM_editRedirectUrl <> "") Then
      Response.Redirect(MM_editRedirectUrl)
    End If
  End If

End If
%>
<%
Dim Recordset1__MMColParam
Recordset1__MMColParam = "1"
If (Request.QueryString("id") <> "") Then 
  Recordset1__MMColParam = Request.QueryString("id")
End If
%>
<%
Dim Recordset1
Dim Recordset1_numRows

Set Recordset1 = Server.CreateObject("ADODB.Recordset")
Recordset1.ActiveConnection = oConn
Recordset1.Source = "SELECT * FROM records WHERE id = " + Replace(Recordset1__MMColParam, "'", "''") + ""
Recordset1.CursorType = 0
Recordset1.CursorLocation = 2
Recordset1.LockType = 1
Recordset1.Open()

Recordset1_numRows = 0
%>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
<title>modify</title>
</head>

<body>
<form method="POST" action="<%=MM_editAction%>" name="form1">
  <table align="center">
    <tr valign="baseline">
      <td>classify:</td>


	
		
					 

	<td><input class="inputcss" name="classify" id="classify" size="15"  value="<%=(Recordset1.Fields.Item("classify").Value)%>"  />
	</span>	  </td>
    </tr>
<tr valign="top">
   <td>title:</td>
      
      <td><textarea name="title" cols="70" rows="5" id="title"><%=(Recordset1.Fields.Item("title").Value)%></textarea></td>    
</tr>
<tr valign="baseline">
      <td>author:</td>
      <td><input name="author" type="text" id="author" size="60" value="<%=(Recordset1.Fields.Item("author").Value)%>"  /></td>
    </tr>
<tr valign="baseline">
      <td>publisher:</td>
      <td><input name="publisher" type="text" id="publisher" size="60" value="<%=(Recordset1.Fields.Item("publisher").Value)%>"  /></td>
    </tr>
<tr valign="top">
      <td>guantu:</td>
      <td><textarea name="gt" cols="70" rows="3" id="gt"><%=(Recordset1.Fields.Item("gt").Value)%></textarea></td>
    </tr>
<tr valign="baseline">
      <td>readDate:</td>
      <td><input name="readdate" type="text" id="readdate" value="<%=(Recordset1.Fields.Item("readdate").Value)%>"   size="60" /></td>
    </tr>
<tr valign="top">
      <td>remark:</td>
      <td><textarea name="remark" cols="70" rows="8" id="remark"><%=(Recordset1.Fields.Item("remark").Value)%></textarea></td>
    </tr>
    <tr valign="baseline">
      <td nowrap align="right">&nbsp;</td>
      <td><input type="submit" value="更新记录">      </td>
    </tr>
  </table>
  
  
  
  <input type="hidden" name="MM_update" value="form1">
  <input type="hidden" name="MM_recordId" value="<%= Recordset1.Fields.Item("id").Value %>">
</form>

<table align="center" width="40%">
<col width="10%" />
<col width="10%" />
<col width="10%" />
<col width="10%" />
    <tr>
      <td>DOS</td>
      <td>传记</td>
      <td>科技</td>
      <td>职场</td>
    </tr>
    <tr>
      <td>PC基础</td>
      <td>历史</td>
      <td>科幻</td>
      <td>技能</td>
    </tr>
    <tr>
      <td>VBA</td>
      <td>名著</td>
      <td>数学</td>
      <td>英文</td>
    </tr>
    <tr>
      <td>编程语言</td>
      <td>思想文化</td>
      <td>经济</td>
      <td>刘能科</td>
    </tr>
    <tr>
      <td>电脑办公</td>
      <td>小说</td>
      <td>军事</td>
      <td></td>
    </tr>
    <tr>
      <td>电脑应用</td>
      <td></td>
      <td>汽车</td>
      <td></td>
    </tr>
    <tr>
      <td>电子</td>
      <td></td>
      <td>物理</td>
      <td></td>
    </tr>
    <tr>
      <td>动态网页</td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
    <tr>
      <td>天文宇宙</td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
    <tr>
      <td>网页网站</td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
  </table>
<p>&nbsp;</p>
</body>
</html>
<%
Recordset1.Close()
Set Recordset1 = Nothing
%>
