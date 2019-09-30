
//bg_even("表格ID属性名","奇数行背景色","偶数行背景色","鼠标经过背景色","点击后背景色");
function bg_even(o,a,b,c,d){
        var t=document.getElementById(o).getElementsByTagName("tr");
        for(var i=0;i<t.length;i++){
                t[i].style.backgroundColor=(t[i].sectionRowIndex%2==0)?a:b;
                t[i].onclick=function(){
                        if(this.x!="1"){
                                this.x="1";
                                this.style.backgroundColor=d;
                        }else{
                                this.x="0";
                                this.style.backgroundColor=(this.sectionRowIndex%2==0)?a:b;
                        }
                }
                t[i].onmouseover=function(){
                        if(this.x!="1")this.style.backgroundColor=c;
                }
                t[i].onmouseout=function(){
                        if(this.x!="1")this.style.backgroundColor=(this.sectionRowIndex%2==0)?a:b;
                }
        }
}

/*另在文档最尾档插入以下JS，表格ID属性名要与文档一致*/

/*<script language="JavaScript" type="text/javascript">
bg_even("browsera","#fff","#F5F5F5","#FFFFCC","#FFFF84");
</script>*/
//bg_even("表格ID属性名","奇数行背景色","偶数行背景色","鼠标经过背景色","点击后背景色");
