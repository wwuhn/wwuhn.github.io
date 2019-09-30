<!--calendar--一部分写在Html,一部份写在JS>-->
/*农历的另一年份时，需更改6处（第6处是节气更改，作为变量中的字符的"Thisyear"不更改）*/
                var cnyear="乙未羊年";/*（第1处）*/
                var spd=24*60*60*1000
				var spd=86400000/*每天的豪秒数*/
				var YDate0=new Date("1/1/2015");/*（第2处）*/
				var y70=new Date("1/1/1970");
				
				var sec0=YDate0-y70;/*1970-公历该年元旦日的豪秒数((41*365+10)*spd=1293840000000)*/
				
				var YDate1 = new Date("2/19/2015");/*（春节的公历日期；第3处）*/
				var dday = (YDate1-YDate0)/(24*60*60*1000);
				//alert(dday);
				
				var totaldayThisyear=0;
				var yearThisyear="29;30;29;29;30;29;30;30;30;29;30;29"; /*该农历年每月天数（第4处）http://www.alfeng.com/Html/?266.html*/
					yearThisyear=yearThisyear.split(";");
					for(i=0;i<yearThisyear.length;i++){
						totaldayThisyear=totaldayThisyear+parseInt(yearThisyear[i]);
					}
					//alert(totaldayThisyear);
				var monthThisyear="正月;二月;三月;四月;五月;六月;七月;八月;九月;十月;十一月;十二月" ;
					monthThisyear=monthThisyear.split(";");/*该农历年月份数（有闰月时要回到变量monthThisyear到中间，如14年“闰八月”）（第5处）*/
				var Dn="初一;初二;初三;初四;初五;初六;初七;初八;初九;初十;十一;十二;十三;十四;十五;十六;十七;十八;十九;二十;廿一;廿二;廿三;廿四;廿五;廿六;廿七;廿八;廿九;三十"; 
				Dn=Dn.split(";"); 
				
				var isnMonth = new
					Array("01-","02-","03-","04-","05-","06-","07-","08-","09-","10-","11-","12-");
				var isnDay = new
					Array("周日","周一","周二","周三","周四","周五","周六","周日");
				var isndate=new Array("01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31");
				today = new Date() ; 
				
				
				var userAgent = navigator.userAgent.toLowerCase();
var browser = 
    (browser = userAgent.match(/qqbrowser\/([\d.]+)/))?"QQbrowser "+browser[1]:
	(browser = userAgent.match(/se\s+2.x/))?"sogou 2.x": //sougou
	(browser = userAgent.match(/msie\s+([\d.]+)/))?"msIE "+browser[1]: //ie
	(browser = userAgent.match(/chrome\/([\d.]+)/))?"chrome "+browser[1]: //chrome
	(browser = userAgent.match(/firefox\/([\d.]+)/))?"FireFox "+browser[1]: //firefox
	(browser = userAgent.match(/version\/([\d.]+)\s+safari\/([\d.]+)/))?"safari "+browser[1]: //safari
	(browser = userAgent.match(/opera\/([\d.]+)([\w\W]+)version\/([\d.]+)/))?"opera "+browser[3]: //opera
	"other browser";

var browser4 = browser.substr(0,4);
//下面的winWidth的值来自于另一个JS的函数；
var Year=today.getYear()

if(browser4 == "msIE"){
var winWidth=1255;/*ie会认为link的JS中的winWidth为0,初始化后恢复；*/
Year=today.getYear();
}
else if(browser4 =="Fire"){
Year=today.getYear()+1900;;
}
else{
Year=today.getYear()+1900;
}
				 
				Daten1=today.getDate(); 
				
				
				sec1=today.getTime();/*现在到1970.1.1之间的豪秒数*/
				sec2=sec1-sec0+8*3600*1000;/*UTC+08*/
				dayed=parseInt(sec2/spd);
				cndayed=dayed-dday;/*假设阴历不会少公历超1月;这个假设有时不一定对*/
				dperm=totaldayThisyear/monthThisyear.length  //
				cnmonth=parseInt(cndayed/dperm);/*农历第n-1月*/
				
				var total2=0;
				for(i=cnmonth+1;i<yearThisyear.length;i++){
				total2=total2+parseInt(yearThisyear[i]);
				}<!--当年剩余月份的天数-->
				
				pdma=totaldayThisyear-cndayed-total2;/*当月还有几天*/
				pdm=yearThisyear[cnmonth]-pdma+1;/*当月的第几天*/
				haveday=totaldayThisyear-cndayed-1;/*尚可期待天数*/
				cnym=monthThisyear[cnmonth]+Dn[pdm-1];/*农历月和日写到一起*/
				//alert(cnym);
				var cnmonthNum=cnmonth+1;
				if(cnmonthNum<10){cnmonthNum="0"+cnmonthNum;}
				var cnDayNum=pdm;
				if(cnDayNum<10){cnDayNum="0"+cnDayNum;}
				var cnmonthDayNum=cnmonthNum+"-"+cnDayNum;
				//alert(cnmonthDayNum);
				enym=isnMonth[today.getMonth()]+isndate[Daten1-1]/*公历月和日写到一起*/
		//switch(cnym)	
		//case "四月初五":cnym=cnym+"&nbsp;"+"立夏";break;
		switch(enym){/*节气更改（第6处）http://jieqi.xpcha.com/*/
		case "02-04":cnym=cnym+"&nbsp;"+"立春";break;
		case "02-19":cnym=cnym+"&nbsp;"+"雨水";break;
		case "03-06":cnym=cnym+"&nbsp;"+"惊蜇";break;
		case "03-21":cnym=cnym+"&nbsp;"+"春分";break;
		case "04-05":cnym=cnym+"&nbsp;"+"清明";break;
		case "04-20":cnym=cnym+"&nbsp;"+"谷雨";break;
	


		case "05-06":cnym=cnym+"&nbsp;"+"立夏";break;
		case "05-21":cnym=cnym+"&nbsp;"+"小满";break;	
		case "06-06":cnym=cnym+"&nbsp;"+"芒种";break;
		case "06-22":cnym=cnym+"&nbsp;"+"夏至";break;
		case "07-07":cnym=cnym+"&nbsp;"+"小暑";break;
		case "07-23":cnym=cnym+"&nbsp;"+"大暑";break;

		
		case "08-08":cnym=cnym+"&nbsp;"+"立秋";break;
		case "08-23":cnym=cnym+"&nbsp;"+"处暑";break;
		case "09-08":cnym=cnym+"&nbsp;"+"白露";break;
		case "09-23":cnym=cnym+"&nbsp;"+"秋分";break;																
		case "10-08":cnym=cnym+"&nbsp;"+"寒露";break;					  
		case "10-24":cnym=cnym+"&nbsp;"+"霜降";break;

																				
		case "11-08":cnym=cnym+"&nbsp;"+"立冬";break;					  
		case "11-22":cnym=cnym+"&nbsp;"+"小雪";break;														
		case "12-07":cnym=cnym+"&nbsp;"+"大雪";break;	
		case "12-22":cnym=cnym+"&nbsp;"+"冬至";break;								
		case "01-06":cnym=cnym+"&nbsp;"+"小寒";break;	
		case "01-20":cnym=cnym+"&nbsp;"+"大寒";break;
		
		case "02-04":cnym=cnym+"&nbsp;"+"立春";break;
		}
		switch(cnym){		
		case "正月初一":cnym=cnym+"&nbsp;"+"春节"; break;	
		case "正月十五":cnym=cnym+"&nbsp;"+"元霄节"; break;	
		case "五月初五":cnym=cnym+"&nbsp;"+"端午节"; break;	
		case "七月十五":cnym=cnym+"&nbsp;"+"中元节"; break;	
		case "七月初七":cnym=cnym+"&nbsp;"+"七夕节"; break;	
		case "八月十五":cnym=cnym+"&nbsp;"+"中秋节";break;	
		case "九月初九":cnym=cnym+"&nbsp;"+"重阳节"; break;	
		case "十二月廿九":cnym=cnym+"&nbsp;"+"除夕"; break;	
		
		case "正月十一":cnym=cnym+"&nbsp;"+"BrotherDay";break;
		case "四月初六":cnym=cnym+"&nbsp;"+"GrandmDay";break;
		case "四月初八":cnym=cnym+"&nbsp;"+"FatherDay";break;
		case "九月廿一":cnym=cnym+"&nbsp;"+"MotherDay"; break;		
		}
		switch(enym){
		case "01-01":enym=enym+"&nbsp;"+"元旦";break;
		case "03-08":enym=enym+"&nbsp;"+"妇女节";break;
		case "05-04":enym=enym+"&nbsp;"+"青年节";break;
		case "06-01":enym=enym+"&nbsp;"+"儿童节";break;
		case "07-01":enym=enym+"&nbsp;"+"建党节";break;
		case "08-01":enym=enym+"&nbsp;"+"建军节";break;
		case "09-10":enym=enym+"&nbsp;"+"教师节";break;

		case "10-01":enym=enym+"&nbsp;"+"国庆节";break;
		}