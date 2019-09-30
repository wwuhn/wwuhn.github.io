<%@LANGUAGE="VBSCRIPT" CODEPAGE="936"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
<script language="javascript">
function check(){

if(document.form1.all.checked)
document.form1.action="resultall.asp";
else
document.form1.action="result.asp";

}
</script>
<style type="text/css">
p{
margin:2px;
text-indent:0em;
}
table{

border-collapse:collapse;
}
table tr>td{

height:38px;

}
.bor{
border:1px solid #888;}
table tr>td+td{
text-align:left;
}
.span1{position:relative}/*包围整个可输入的下拉框，以下三个元素*/
.span2{
	margin-left:45px;
	overflow:hidden;}/*包围select元素*/
.selectcss{     /*select元素*/
	width:339px;
	margin-left:-45px;
	margin-left:-46px\9;
 }
.key{       /*input元素*/
	width:315px;
	font-size:14px;
	height:16px;
	margin-top:0px;
	position:absolute;
	left:0px;
}
</style>
<title>search</title>
</head>

<body>
<table width="650" align="center">
<tr><td style="text-align:left; font-size:1.2m; font-weight:bold">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;查询界面</td></tr>
 </table>
<form action="result.asp" method="post" name="form1" target="_blank" id="form1">
  <table width="850" border="0" align="center">
    
    <tr>
      <td>请选择需要查询的列:</td>
      <td><input type="radio" name="colkey" value="classify" />classify</td>
      <td><input type="radio" name="colkey" value="title" />title</td>
      <td><input type="radio" name="colkey" value="author" />author</td>
	  <td><input type="radio" name="colkey" value="publisher" />author</td>
	  <td><input type="radio" name="colkey" value="gt" />author</td>
	  <td><input type="radio" name="colkey" value="readdate" />author</td>
	  <td><input type="radio" name="colkey" value="remark" />author</td>
	  
	  <td><input type="radio" name="colkey" id="all" checked="checked" />all cols</td>
	  
    </tr>
    <tr>
      <td><p>需要在上述选中的列中&nbsp;</p>
      <p>模糊匹配的关键字: </p></td>
      <td colspan="5">
	  <span class="span1">
		<span class="span2">
		<select class="selectcss" onchange="this.parentNode.nextSibling.value=this.value">
			 
<option value=""></option>
<option value="DOS">DOS</option>
<option value="PC基础">PC基础</option>
<option value="VBA">VBA</option>
<option value="编程语言">编程语言</option>
<option value="传记">传记</option>
<option value="电脑办公">电脑办公</option>
<option value="电脑应用">电脑应用</option>
<option value="电子">电子</option>
<option value="动态网页">动态网页</option>
<option value="技能">技能</option>
<option value="经济">经济</option>
<option value="军事">军事</option>
<option value="科幻">科幻</option>
<option value="科技">科技</option>
<option value="历史">历史</option>
<option value="刘能科">刘能科</option>
<option value="名著">名著</option>
<option value="汽车">汽车</option>
<option value="数学">数学</option>
<option value="思想文化">思想文化</option>
<option value="天文宇宙">天文宇宙</option>
<option value="网页网站">网页网站</option>
<option value="物理">物理</option>
<option value="小说">小说</option>
<option value="英文">英文</option>
<option value="职场">职场</option>


		</select>
		</span><input class="key" name="key" id="key" size="15" />
	</span>	  
	  </td>
	  
      <td><input onclick="check();" type="submit" name="Submit" value="search" /></td>
    </tr>
  </table>
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
</form>
</body>
</html>
