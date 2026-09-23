# 确保已安装：pip install pyecharts
import json
from pyecharts.charts import Map
from pyecharts import options as opts
from pyecharts.commons.utils import JsCode

# 国家信息字典：英文名 -> [音标, 中文名, 所属大洲, 领土面积, 人口]
# 覆盖全部 193 个联合国会员国，另含梵蒂冈、巴勒斯坦 2 个联大永久观察员国。
# 面积为常用公开口径（约数），人口为 2023—2024 年量级估算。
country_info = {
    # ---------------- 亚洲（47 会员国） ----------------
    "Afghanistan":  ["/æfˈɡænɪstæn/", "阿富汗", "亚洲", "约65.2万 km²", "约4250万"],
    "Armenia":      ["/ɑːrˈmiːniə/", "亚美尼亚", "亚洲（外高加索，有时归欧洲）", "约2.97万 km²", "约300万"],
    "Azerbaijan":   ["/ˌæzərˈbaɪdʒɑːn/", "阿塞拜疆", "亚洲（外高加索，有时归欧洲）", "约8.66万 km²", "约1010万"],
    "Bahrain":      ["/bɑːˈreɪn/", "巴林", "亚洲", "约787 km²", "约160万"],
    "Bangladesh":   ["/ˌbæŋɡləˈdɛʃ/", "孟加拉国", "亚洲", "约14.8万 km²", "约1.73亿"],
    "Bhutan":       ["/ˈbuːtɑːn/", "不丹", "亚洲", "约3.84万 km²", "约78万"],
    "Brunei":       ["/bruːˈnaɪ/", "文莱", "亚洲", "约5765 km²", "约45万"],
    "Cambodia":     ["/kæmˈboʊdiə/", "柬埔寨", "亚洲", "约18.1万 km²", "约1700万"],
    "China":        ["/ˈtʃaɪnə/", "中国", "亚洲", "约960万 km²", "约14.25亿"],
    "Cyprus":       ["/ˈsaɪprəs/", "塞浦路斯", "亚洲（地理；政制上常归欧洲）", "约9251 km²", "约130万"],
    "East Timor":   ["/ˌiːst ˈtiːmɔːr/", "东帝汶", "亚洲（东南亚，有时归大洋洲）", "约1.5万 km²", "约140万"],
    "Georgia":      ["/ˈdʒɔːrdʒə/", "格鲁吉亚", "亚洲（外高加索，有时归欧洲）", "约6.97万 km²", "约370万"],
    "India":        ["/ˈɪndiə/", "印度", "亚洲", "约298万 km²", "约14.4亿"],
    "Indonesia":    ["/ˌɪndəˈniːʒə/", "印度尼西亚", "亚洲（部分领土在大洋洲）", "约190万 km²", "约2.78亿"],
    "Iran":         ["/ɪˈrɑːn/", "伊朗", "亚洲", "约165万 km²", "约8900万"],
    "Iraq":         ["/ɪˈrɑːk/", "伊拉克", "亚洲", "约43.8万 km²", "约4600万"],
    "Israel":       ["/ˈɪzreɪəl/", "以色列", "亚洲", "约2.2万 km²（含控制区）", "约990万"],
    "Japan":        ["/dʒəˈpæn/", "日本", "亚洲", "约37.8万 km²", "约1.23亿"],
    "Jordan":       ["/ˈdʒɔːrdən/", "约旦", "亚洲", "约8.93万 km²", "约1140万"],
    "Kazakhstan":   ["/ˌkɑːzɑːkˈstæn/", "哈萨克斯坦", "亚洲（乌拉尔河以西一小部在欧洲）", "约272万 km²", "约2000万"],
    "Kuwait":       ["/kʊˈweɪt/", "科威特", "亚洲", "约1.78万 km²", "约430万"],
    "Kyrgyzstan":   ["/ˌɡɪrˈɡɪzstæn/", "吉尔吉斯斯坦", "亚洲", "约20万 km²", "约700万"],
    "Laos":         ["/laʊs/", "老挝", "亚洲", "约23.7万 km²", "约760万"],
    "Lebanon":      ["/ˈlɛbənɒn/", "黎巴嫩", "亚洲", "约1.05万 km²", "约540万"],
    "Malaysia":     ["/məˈleɪʒə/", "马来西亚", "亚洲", "约33.1万 km²", "约3400万"],
    "Maldives":     ["/ˈmɔːldɪvz/", "马尔代夫", "亚洲", "约298 km²", "约52万"],
    "Mongolia":     ["/mɒŋˈɡoʊliə/", "蒙古", "亚洲", "约156万 km²", "约340万"],
    "Myanmar":      ["/ˈmjɑːnmɑːr/", "缅甸", "亚洲", "约67.7万 km²", "约5400万"],
    "Nepal":        ["/nɪˈpɔːl/", "尼泊尔", "亚洲", "约14.7万 km²", "约3050万"],
    "North Korea":  ["/nɔːrθ ˈkɔːriə/", "朝鲜", "亚洲", "约12.3万 km²", "约2600万"],
    "Oman":         ["/oʊˈmɑːn/", "阿曼", "亚洲", "约31万 km²", "约470万"],
    "Pakistan":     ["/ˈpɑːkɪstæn/", "巴基斯坦", "亚洲", "约88.2万 km²（含巴控克什米尔）", "约2.4亿"],
    "Philippines":  ["/ˈfɪlɪpiːnz/", "菲律宾", "亚洲", "约30万 km²", "约1.17亿"],
    "Qatar":        ["/kəˈtɑːr/", "卡塔尔", "亚洲", "约1.16万 km²", "约280万"],
    "Saudi Arabia": ["/ˌsaʊdi əˈreɪbiə/", "沙特阿拉伯", "亚洲", "约215万 km²", "约3700万"],
    "Singapore":    ["/ˌsɪŋəˈpɔːr/", "新加坡", "亚洲", "约733 km²", "约590万"],
    "South Korea":  ["/saʊθ ˈkɔːriə/", "韩国", "亚洲", "约10万 km²", "约5200万"],
    "Sri Lanka":    ["/ʃriː ˈlɑːŋkə/", "斯里兰卡", "亚洲", "约6.56万 km²", "约2200万"],
    "Syria":        ["/ˈsɪriə/", "叙利亚", "亚洲", "约18.5万 km²", "约2300万"],
    "Tajikistan":   ["/təˈdʒiːkɪstæn/", "塔吉克斯坦", "亚洲", "约14.3万 km²", "约1000万"],
    "Thailand":     ["/ˈtaɪlænd/", "泰国", "亚洲", "约51.3万 km²", "约7200万"],
    "Turkey":       ["/ˈtɜːrki/", "土耳其", "亚洲（约97%；西北隅在欧洲）", "约78.4万 km²", "约8580万"],
    "Turkmenistan": ["/ˌtɜːrkməˈnɪstæn/", "土库曼斯坦", "亚洲", "约49.1万 km²", "约630万"],
    "UAE":          ["/juːˌeɪ əˈrɛmɪtʃeɪt/", "阿联酋", "亚洲", "约8.36万 km²", "约950万"],
    "Uzbekistan":   ["/ˌʌzbɛkɪˈstæn/", "乌兹别克斯坦", "亚洲", "约44.7万 km²", "约3500万"],
    "Vietnam":      ["/ˌvjɛtˈnɑːm/", "越南", "亚洲", "约33.1万 km²", "约1亿"],
    "Yemen":        ["/ˈjɛmən/", "也门", "亚洲", "约52.8万 km²", "约3500万"],
    # 观察员国
    "Palestine":    ["/ˈpælstaɪn/", "巴勒斯坦", "亚洲", "约6220 km²（约旦河西岸+加沙）", "约550万"],
    # ---------------- 非洲（54 会员国） ----------------
    "Algeria":      ["/ælˈdʒɪriə/", "阿尔及利亚", "非洲", "约238万 km²", "约4560万"],
    "Angola":       ["/æŋˈɡoʊlə/", "安哥拉", "非洲", "约125万 km²", "约3700万"],
    "Benin":        ["/bɛˈniːn/", "贝宁", "非洲", "约11.5万 km²", "约1370万"],
    "Botswana":     ["/bɒtˈswɑːnə/", "博茨瓦纳", "非洲", "约58.2万 km²", "约270万"],
    "Burkina Faso": ["/ˌbɜːrkiːnə ˈfæsoʊ/", "布基纳法索", "非洲", "约27.4万 km²", "约2300万"],
    "Burundi":      ["/buːˈrʌndi/", "布隆迪", "非洲", "约2.78万 km²", "约1300万"],
    "Cabo Verde":   ["/ˌkɑːboʊ ˈvɛərdi/", "佛得角", "非洲", "约4033 km²", "约57万"],
    "Cameroon":     ["/ˈkæməˈruːn/", "喀麦隆", "非洲", "约47.5万 km²", "约2800万"],
    "Central African Republic": ["/ˌsɛntrəl ˈæfrɪkən/", "中非", "非洲", "约62.3万 km²", "约570万"],
    "Chad":         ["/tʃæd/", "乍得", "非洲", "约128万 km²", "约1940万"],
    "Comoros":      ["/ˈkɒməroʊz/", "科摩罗", "非洲", "约2236 km²", "约89万"],
    "Congo":        ["/ˈkɒŋɡoʊ/", "刚果（布）", "非洲", "约34.2万 km²", "约610万"],
    "Democratic Republic of the Congo": ["/ˌdɛməˈkrætɪk/", "刚果（金）", "非洲", "约234.5万 km²", "约1.04亿"],
    "Côte d'Ivoire": ["/ˌkoʊt dɪˈvɔːr/", "科特迪瓦", "非洲", "约32.2万 km²", "约2900万"],
    "Djibouti":     ["/ˈdʒiːbuːti/", "吉布提", "非洲", "约2.32万 km²", "约110万"],
    "Egypt":        ["/ˈiːdʒɪpt/", "埃及", "非洲（西奈半岛属亚洲）", "约100万 km²", "约1.14亿"],
    "Equatorial Guinea": ["/ˌiːkwəˈtɔːriəl/", "赤道几内亚", "非洲", "约2.81万 km²", "约170万"],
    "Eritrea":      ["/ˌɛrɪˈtreɪə/", "厄立特里亚", "非洲", "约11.8万 km²", "约370万"],
    "Eswatini":     ["/ˌɛswɑːˈtiːni/", "埃斯瓦蒂尼", "非洲", "约1.74万 km²", "约120万"],
    "Ethiopia":     ["/ˌiːθiˈoʊpiə/", "埃塞俄比亚", "非洲", "约110万 km²", "约1.28亿"],
    "Gabon":        ["/ɡəˈbɒn/", "加蓬", "非洲", "约26.8万 km²", "约240万"],
    "Gambia":       ["/ˈɡæmbiə/", "冈比亚", "非洲", "约1.13万 km²", "约280万"],
    "Ghana":        ["/ˈɡɑːnə/", "加纳", "非洲", "约23.9万 km²", "约3400万"],
    "Guinea":       ["/ˈɡɪni/", "几内亚", "非洲", "约24.6万 km²", "约1400万"],
    "Guinea-Bissau": ["/ˌɡɪni bɪˈsaʊ/", "几内亚比绍", "非洲", "约3.61万 km²", "约220万"],
    "Kenya":        ["/ˈkɛnjə/", "肯尼亚", "非洲", "约58万 km²", "约5600万"],
    "Lesotho":      ["/lɛˈsuːtuː/", "莱索托", "非洲", "约3.04万 km²", "约230万"],
    "Liberia":      ["/laɪˈbɪəriə/", "利比里亚", "非洲", "约11.1万 km²", "约550万"],
    "Libya":        ["/ˈlɪbiə/", "利比亚", "非洲", "约176万 km²", "约690万"],
    "Madagascar":   ["/mædəˈɡæskər/", "马达加斯加", "非洲", "约58.7万 km²", "约3100万"],
    "Malawi":       ["/məˈlɑːwiː/", "马拉维", "非洲", "约11.8万 km²", "约2100万"],
    "Mali":         ["/ˈmɑːli/", "马里", "非洲", "约124万 km²", "约2390万"],
    "Mauritania":   ["/ˌmɔːrɪˈteɪniə/", "毛里塔尼亚", "非洲", "约103万 km²", "约490万"],
    "Mauritius":    ["/mɔːˈrɪʃiəs/", "毛里求斯", "非洲", "约2040 km²", "约126万"],
    "Morocco":      ["/məˈrɒkoʊ/", "摩洛哥", "非洲", "约44.7万 km²（不含西撒）", "约3780万"],
    "Mozambique":   ["/moʊˌzæmˈbiːk/", "莫桑比克", "非洲", "约80万 km²", "约3400万"],
    "Namibia":      ["/nəˈmɪbiə/", "纳米比亚", "非洲", "约82.4万 km²", "约260万"],
    "Niger":        ["/naɪˈdʒɛr/", "尼日尔", "非洲", "约127万 km²", "约2700万"],
    "Nigeria":      ["/naɪˈdʒɪəriə/", "尼日利亚", "非洲", "约92.4万 km²", "约2.33亿"],
    "Rwanda":       ["/ruːˈændə/", "卢旺达", "非洲", "约2.63万 km²", "约1450万"],
    "São Tomé and Príncipe": ["/saʊ təˈmeɪ/", "圣多美和普林西比", "非洲", "约964 km²", "约23万"],
    "Senegal":      ["/ˈsɛnɪɡəl/", "塞内加尔", "非洲", "约19.7万 km²", "约1800万"],
    "Seychelles":   ["/seɪˈʃɛlz/", "塞舌尔", "非洲", "约455 km²", "约12万"],
    "Sierra Leone": ["/siˈɛərə liˈoʊn/", "塞拉利昂", "非洲", "约7.23万 km²", "约870万"],
    "Somalia":      ["/soʊˈmɑːliə/", "索马里", "非洲", "约63.8万 km²", "约1850万"],
    "South Africa": ["/saʊθ ˈæfrɪkə/", "南非", "非洲", "约122万 km²", "约6000万"],
    "South Sudan":  ["/saʊθ ˈsuːdæn/", "南苏丹", "非洲", "约62万 km²", "约1110万"],
    "Sudan":        ["/suːˈdæn/", "苏丹", "非洲", "约188万 km²", "约4900万"],
    "Tanzania":     ["/tænˈzæniə/", "坦桑尼亚", "非洲", "约94.5万 km²", "约6860万"],
    "Togo":         ["/ˈtoʊɡoʊ/", "多哥", "非洲", "约5.68万 km²", "约940万"],
    "Tunisia":      ["/tjuːˈniːʒə/", "突尼斯", "非洲", "约16.4万 km²", "约1250万"],
    "Uganda":       ["/juːˈɡændə/", "乌干达", "非洲", "约24.2万 km²", "约4900万"],
    "Zambia":       ["/ˈzæmbiə/", "赞比亚", "非洲", "约75.3万 km²", "约2090万"],
    "Zimbabwe":     ["/zɪmˈbɑːbweɪ/", "津巴布韦", "非洲", "约39.1万 km²", "约1680万"],
    # ---------------- 欧洲（43 会员国） ----------------
    "Albania":      ["/ælˈbeɪniə/", "阿尔巴尼亚", "欧洲", "约2.87万 km²", "约280万"],
    "Andorra":      ["/ænˈdɔːrə/", "安道尔", "欧洲", "约468 km²", "约8万"],
    "Austria":      ["/ˈɔːstriə/", "奥地利", "欧洲", "约8.39万 km²", "约920万"],
    "Belarus":      ["/ˌbɛləˈrus/", "白俄罗斯", "欧洲", "约20.8万 km²", "约920万"],
    "Belgium":      ["/ˈbɛldʒəm/", "比利时", "欧洲", "约3.07万 km²", "约1180万"],
    "Bosnia and Herzegovina": ["/ˈbɒzniə/", "波黑", "欧洲", "约5.12万 km²", "约320万"],
    "Bulgaria":     ["/bʌlˈɡɛəriə/", "保加利亚", "欧洲", "约11.1万 km²", "约640万"],
    "Croatia":      ["/kroʊˈeɪʃə/", "克罗地亚", "欧洲", "约5.66万 km²", "约385万"],
    "Czech Republic": ["/tʃɛk/", "捷克", "欧洲", "约7.89万 km²", "约1090万"],
    "Denmark":      ["/ˈdɛnmɑːrk/", "丹麦", "欧洲（本土；含自治领更大）", "约4.31万 km²（本土）", "约590万"],
    "Estonia":      ["/ɛˈstəniə/", "爱沙尼亚", "欧洲", "约4.53万 km²", "约137万"],
    "Finland":      ["/ˈfɪnlənd/", "芬兰", "欧洲", "约33.8万 km²", "约560万"],
    "France":       ["/fræns/", "法国", "欧洲（含海外大区约64.4万 km²）", "约55.2万 km²（本土）", "约6800万"],
    "Germany":      ["/ˈdʒɜːrməni/", "德国", "欧洲", "约35.8万 km²", "约8450万"],
    "Greece":       ["/ɡriːs/", "希腊", "欧洲", "约13.2万 km²", "约1040万"],
    "Hungary":      ["/ˈhʌŋɡəri/", "匈牙利", "欧洲", "约9.3万 km²", "约960万"],
    "Iceland":      ["/ˈaɪslənd/", "冰岛", "欧洲", "约10.3万 km²", "约39万"],
    "Ireland":      ["/ˈaɪərlənd/", "爱尔兰", "欧洲", "约7.03万 km²", "约530万"],
    "Italy":        ["/ˈɪtəli/", "意大利", "欧洲", "约30.1万 km²", "约5890万"],
    "Latvia":       ["/ˈlætviə/", "拉脱维亚", "欧洲", "约6.46万 km²", "约188万"],
    "Liechtenstein": ["/ˈlɪktənstaɪn/", "列支敦士登", "欧洲", "约160 km²", "约4万"],
    "Lithuania":    ["/ˌlɪθjuˈeɪniə/", "立陶宛", "欧洲", "约6.53万 km²", "约289万"],
    "Luxembourg":   ["/ˈlʌksəmbɜːrɡ/", "卢森堡", "欧洲", "约2586 km²", "约67万"],
    "Malta":        ["/ˈmɔːltə/", "马耳他", "欧洲", "约316 km²", "约54万"],
    "Moldova":      ["/ˈmɒldəvə/", "摩尔多瓦", "欧洲", "约3.38万 km²", "约250万"],
    "Monaco":       ["/ˈmɒnəkoʊ/", "摩纳哥", "欧洲", "约2.08 km²", "约3.7万"],
    "Montenegro":   ["/ˌmɒntɪˈneɪɡroʊ/", "黑山", "欧洲", "约1.39万 km²", "约62万"],
    "Netherlands":  ["/ˈnɛðərləndz/", "荷兰", "欧洲（本土）", "约4.15万 km²（本土）", "约1800万"],
    "North Macedonia": ["/nɔːrθ məˈsidoʊniə/", "北马其顿", "欧洲", "约2.57万 km²", "约180万"],
    "Norway":       ["/ˈnɔːrweɪ/", "挪威", "欧洲", "约38.5万 km²（本土）", "约560万"],
    "Poland":       ["/ˈpoʊlənd/", "波兰", "欧洲", "约31.3万 km²", "约3670万"],
    "Portugal":     ["/ˈpɔːrtuɡəl/", "葡萄牙", "欧洲", "约9.22万 km²", "约1050万"],
    "Romania":      ["/roʊˈmeɪniə/", "罗马尼亚", "欧洲", "约23.8万 km²", "约1900万"],
    "Russia":       ["/ˈrʌʃə/", "俄罗斯", "欧洲（地跨欧亚，首都偏欧）", "约1710万 km²", "约1.44亿"],
    "San Marino":   ["/ˌsæn məˈriːnoʊ/", "圣马力诺", "欧洲", "约61 km²", "约3.4万"],
    "Serbia":       ["/ˈsɜːrbiə/", "塞尔维亚", "欧洲", "约7.75万 km²（不含科索沃）", "约660万"],
    "Slovakia":     ["/sloʊˈvækiə/", "斯洛伐克", "欧洲", "约4.9万 km²", "约540万"],
    "Slovenia":     ["/sloʊˈviːniə/", "斯洛文尼亚", "欧洲", "约2.03万 km²", "约210万"],
    "Spain":        ["/speɪn/", "西班牙", "欧洲", "约50.6万 km²", "约4830万"],
    "Sweden":       ["/ˈswiːdɪn/", "瑞典", "欧洲", "约45万 km²", "约1050万"],
    "Switzerland":  ["/ˈswɪtsərlənd/", "瑞士", "欧洲", "约4.13万 km²", "约890万"],
    "Ukraine":      ["/juːˈkreɪn/", "乌克兰", "欧洲", "约60.4万 km²", "约3700万（含出境人口波动）"],
    "United Kingdom": ["/juːˈnaɪtɪd ˈkɪŋdəm/", "英国", "欧洲", "约24.4万 km²", "约6800万"],
    # 观察员国
    "Vatican":      ["/ˈvætɪkən/", "梵蒂冈", "欧洲", "约0.44 km²", "约800人"],
    # ---------------- 北美洲与加勒比（23 会员国） ----------------
    "Antigua and Barbuda": ["/ænˈtiːɡə/", "安提瓜和巴布达", "北美洲", "约443 km²", "约9.4万"],
    "The Bahamas":  ["/bəˈhæməz/", "巴哈马", "北美洲", "约1.4万 km²", "约40万"],
    "Barbados":     ["/bɑːrˈbeɪdoʊz/", "巴巴多斯", "北美洲", "约439 km²", "约28万"],
    "Belize":       ["/bəˈliːz/", "伯利兹", "北美洲", "约2.3万 km²", "约41万"],
    "Canada":       ["/ˈkænədə/", "加拿大", "北美洲", "约998万 km²", "约4100万"],
    "Costa Rica":   ["/ˌkɒstə ˈriːkə/", "哥斯达黎加", "北美洲", "约5.11万 km²", "约520万"],
    "Cuba":         ["/ˈkjuːbə/", "古巴", "北美洲", "约11万 km²", "约1110万"],
    "Dominica":     ["/ˌdɒmɪˈniːkə/", "多米尼克", "北美洲", "约751 km²", "约6.7万"],
    "Dominican Republic": ["/dəˈmɪnɪkən/", "多米尼加", "北美洲", "约4.87万 km²", "约1130万"],
    "El Salvador":  ["/ɛl səˈlvədɔːr/", "萨尔瓦多", "北美洲", "约2.1万 km²", "约640万"],
    "Grenada":      ["/ɡrɪˈnædə/", "格林纳达", "北美洲", "约344 km²", "约12.6万"],
    "Guatemala":    ["/ˌɡwɑːtəˈmɑːlə/", "危地马拉", "北美洲", "约10.9万 km²", "约1790万"],
    "Haiti":        ["/ˈheɪti/", "海地", "北美洲", "约2.78万 km²", "约1170万"],
    "Honduras":     ["/hɒnˈdjʊərəs/", "洪都拉斯", "北美洲", "约11.2万 km²", "约1060万"],
    "Jamaica":      ["/dʒəˈmeɪkə/", "牙买加", "北美洲", "约1.1万 km²", "约280万"],
    "Mexico":       ["/ˈmɛksɪkoʊ/", "墨西哥", "北美洲", "约196万 km²", "约1.29亿"],
    "Nicaragua":    ["/ˌnɪkəˈrɑːɡwə/", "尼加拉瓜", "北美洲", "约13万 km²", "约700万"],
    "Panama":       ["/ˈpænəmə/", "巴拿马", "北美洲（连接南美的地峡国）", "约7.55万 km²", "约450万"],
    "Saint Kitts and Nevis": ["/seɪnt kɪts/", "圣基茨和尼维斯", "北美洲", "约261 km²", "约4.8万"],
    "Saint Lucia":  ["/seɪnt ˈluːʃə/", "圣卢西亚", "北美洲", "约617 km²", "约18.1万"],
    "Saint Vincent and the Grenadines": ["/vɪnˈsɛnt/", "圣文森特和格林纳丁斯", "北美洲", "约389 km²", "约4.5万"],
    "Trinidad and Tobago": ["/ˈtrɪnɪdæd/", "特立尼达和多巴哥", "北美洲", "约5130 km²", "约153万"],
    "United States": ["/juːˈnaɪtɪd steɪts/", "美国", "北美洲", "约983万 km²", "约3.4亿"],
    # ---------------- 南美洲（12 会员国） ----------------
    "Argentina":    ["/ˌɑːrdʒənˈtiːnə/", "阿根廷", "南美洲", "约278万 km²", "约4660万"],
    "Bolivia":      ["/bəˈlɪviə/", "玻利维亚", "南美洲", "约110万 km²", "约1240万"],
    "Brazil":       ["/brəˈzɪl/", "巴西", "南美洲", "约851万 km²", "约2.17亿"],
    "Chile":        ["/ˈtʃɪleɪ/", "智利", "南美洲", "约75.6万 km²", "约2000万"],
    "Colombia":     ["/kəˈlʌmbiə/", "哥伦比亚", "南美洲", "约114万 km²", "约5290万"],
    "Ecuador":      ["/ˈɛkwədɔːr/", "厄瓜多尔", "南美洲", "约25.6万 km²", "约1830万"],
    "Guyana":       ["/ɡaɪˈænə/", "圭亚那", "南美洲", "约21.5万 km²", "约84万"],
    "Paraguay":     ["/ˈpærəɡweɪ/", "巴拉圭", "南美洲", "约40.7万 km²", "约680万"],
    "Peru":         ["/pəˈruː/", "秘鲁", "南美洲", "约128.5万 km²", "约3440万"],
    "Suriname":     ["/ˈsʊərɪnæm/", "苏里南", "南美洲", "约16.4万 km²", "约63万"],
    "Uruguay":      ["/ˈjʊərəɡweɪ/", "乌拉圭", "南美洲", "约17.6万 km²", "约340万"],
    "Venezuela":    ["/ˌvɛnzəˈweɪlə/", "委内瑞拉", "南美洲", "约91.6万 km²", "约2840万"],
    # ---------------- 大洋洲（14 会员国） ----------------
    "Australia":    ["/ɔːˈstreɪliə/", "澳大利亚", "大洋洲", "约769万 km²", "约2700万"],
    "Fiji":         ["/ˈfiːdʒi/", "斐济", "大洋洲", "约1.83万 km²", "约93万"],
    "Kiribati":     ["/ˌkɪrɪˈbɑːsti/", "基里巴斯", "大洋洲", "约811 km²", "约13万"],
    "Marshall Islands": ["/ˈmɑːrʃəl/", "马绍尔群岛", "大洋洲", "约181 km²", "约4.2万"],
    "Micronesia":   ["/ˌmaɪkrəˈniːʒə/", "密克罗尼西亚联邦", "大洋洲", "约702 km²", "约11.5万"],
    "Nauru":        ["/nɔːˈruː/", "瑙鲁", "大洋洲", "约21 km²", "约1.2万"],
    "New Zealand":  ["/ˈnjuː ziːlənd/", "新西兰", "大洋洲", "约26.8万 km²", "约530万"],
    "Palau":        ["/pəˈlaʊ/", "帕劳", "大洋洲", "约459 km²", "约1.8万"],
    "Papua New Guinea": ["/ˈpɑːpuə/", "巴布亚新几内亚", "大洋洲", "约46.3万 km²", "约1030万"],
    "Samoa":        ["/səˈmoʊə/", "萨摩亚", "大洋洲", "约2944 km²", "约22万"],
    "Solomon Islands": ["/ˈsɒləmən/", "所罗门群岛", "大洋洲", "约2.9万 km²", "约74万"],
    "Tonga":        ["/ˈtɒŋɡə/", "汤加", "大洋洲", "约748 km²", "约10.4万"],
    "Tuvalu":       ["/ˌtuːˈvɑːluː/", "图瓦卢", "大洋洲", "约26 km²", "约1.1万"],
    "Vanuatu":      ["/ˌvɑːnuˈɑːtuː/", "瓦努阿图", "大洋洲", "约1.22万 km²", "约33万"],
}

# 别名映射：世界地图数据中同一国家可能使用的其他名称写法 -> 规范键
aliases = {
    "USA": "United States",
    "United States of America": "United States",
    "Republic of Korea": "South Korea",
    "Korea": "South Korea",
    "Dem. Rep. Korea": "North Korea",
    "Dem. People's Rep. Korea": "North Korea",
    "Czechia": "Czech Republic",
    "Czech Rep.": "Czech Republic",
    "Russian Federation": "Russia",
    "Iran (Islamic Republic of)": "Iran",
    "Islamic Republic of Iran": "Iran",
    "Syrian Arab Republic": "Syria",
    "Lao People's Democratic Republic": "Laos",
    "Viet Nam": "Vietnam",
    "Brunei Darussalam": "Brunei",
    "Bahamas": "The Bahamas",
    "Bosnia and Herz.": "Bosnia and Herzegovina",
    "Central African Rep.": "Central African Republic",
    "Congo Rep.": "Congo",
    "Republic of the Congo": "Congo",
    "Rep. Congo": "Congo",
    "Dem. Rep. Congo": "Democratic Republic of the Congo",
    "Congo (Dem. Rep.)": "Democratic Republic of the Congo",
    "Congo-Kinshasa": "Democratic Republic of the Congo",
    "Ivory Coast": "Côte d'Ivoire",
    "Cote D'Ivoire": "Côte d'Ivoire",
    "Dominican Rep.": "Dominican Republic",
    "Eq. Guinea": "Equatorial Guinea",
    "S. Sudan": "South Sudan",
    "Solomon Is.": "Solomon Islands",
    "Timor-Leste": "East Timor",
    "Swaziland": "Eswatini",
    "eSwatini": "Eswatini",
    "Macedonia": "North Macedonia",
    "FYROM": "North Macedonia",
    "Türkiye": "Turkey",
    "United Republic of Tanzania": "Tanzania",
    "Federated States of Micronesia": "Micronesia",
    "Marshall Is.": "Marshall Islands",
    "St. Kitts and Nevis": "Saint Kitts and Nevis",
    "St. Lucia": "Saint Lucia",
    "St. Vincent and the Grenadines": "Saint Vincent and the Grenadines",
    "Saint Vincent": "Saint Vincent and the Grenadines",
    "Sao Tome and Principe": "São Tomé and Príncipe",
    "Sao Tomé and Príncipe": "São Tomé and Príncipe",
    "Cape Verde": "Cabo Verde",
    "Kyrgyz Republic": "Kyrgyzstan",
    "Burma": "Myanmar",
    "United Arab Emirates": "UAE",
    "West Bank and Gaza": "Palestine",
    "Vatican City": "Vatican",
    "Holy See": "Vatican",
}
for _alias, _key in aliases.items():
    if _key in country_info:
        country_info[_alias] = country_info[_key]

# 1. 准备分组数据 (国家, 数值)
# 这里用各大洲作为分组示例，你可以替换成任何你想要的分组逻辑

# 第一组：亚洲部分国家 (value: 30)
group_1 = [
    ("China", 90), ("Japan", 60), ("South Korea", 30),
    ("India", 10), ("Thailand", 70), ("Vietnam", 20)
]

# 第二组：欧洲部分国家 (value: 50)
group_2 = [
    ("Russia", 0), ("Germany", 20), ("France", 50),
    ("United Kingdom", 90), ("Italy", 40), ("Spain", 80)
]

# 第三组：美洲部分国家 (value: 70)
group_3 = [
    ("United States", 10), ("Canada", 50), ("Brazil", 70),
    ("Mexico", 9), ("Argentina", 30)
]

# 第四组：其他大洲国家 (value: 90)
group_4 = [
    ("Australia", 10), ("Egypt", 40), ("South Africa", 70),
    ("Nigeria", 90), ("Saudi Arabia", 20)
]

# 合并所有数据
data = group_1 + group_2 + group_3 + group_4

# 2. 创建全屏地图
c = (
    Map(init_opts=opts.InitOpts(width="100%", height="100vh"))
    .add(
        "",
        data,
        "world",  # 核心改动：地图类型从 "china" 变为 "world"
        label_opts=opts.LabelOpts(is_show=False), # 隐藏国家名
    )
    .set_global_opts(
        visualmap_opts=opts.VisualMapOpts(is_show=False),
        tooltip_opts=opts.TooltipOpts(
            is_show=True,
            trigger="item",
            formatter=JsCode(
                "function(p){"
                "var info=countryInfo[p.name];"
                "if(!info){return p.name;}"
                "return '<div style=\"line-height:1.8\">'"
                "+'<b>'+info[1]+'</b>（'+p.name+'  '+info[0]+'）<br>'"
                "+'大洲：'+info[2]+'<br>'"
                "+'面积：'+info[3]+'<br>'"
                "+'人口：'+info[4]+'</div>';"
                "}"
            ),
        ), # 悬停显示国家信息卡片
    )
)

# 3. 注入国家信息字典（json.dumps 保证含撇号等国家名不破坏 JS）
c.add_js_funcs("var countryInfo = " + json.dumps(country_info, ensure_ascii=False) + ";")

# 4. 注入 CSS，去掉页面默认边距，实现真正全屏
c.add_js_funcs("""
    document.body.style.margin = '0';
    document.body.style.padding = '0';
    document.body.style.overflow = 'hidden';
""")

# 5. 生成文件
c.render("worldBlank.html")
print("世界地图已生成，请查看 worldBlank.html")
