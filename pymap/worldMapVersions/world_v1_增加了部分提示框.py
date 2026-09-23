# 确保已安装：pip install pyecharts
from pyecharts.charts import Map
from pyecharts import options as opts
from pyecharts.commons.utils import JsCode

# 国家信息字典：英文国名 -> [音标, 中文名, 所属大洲, 领土面积, 人口]
country_info = {
    "China":          ["/ˈtʃaɪnə/", "中国", "亚洲", "约960万 km²", "约14.25亿"],
    "Japan":          ["/dʒəˈpæn/", "日本", "亚洲", "约37.8万 km²", "约1.23亿"],
    "South Korea":    ["/kəˈriːə/", "韩国", "亚洲", "约10万 km²", "约5200万"],
    "India":          ["/ˈɪndiə/", "印度", "亚洲", "约298万 km²", "约14.4亿"],
    "Thailand":       ["/ˈtaɪlænd/", "泰国", "亚洲", "约51.3万 km²", "约7200万"],
    "Vietnam":        ["/ˌvjɛtˈnɑːm/", "越南", "亚洲", "约33.1万 km²", "约1亿"],
    "Russia":         ["/ˈrʌʃə/", "俄罗斯", "欧洲（地跨欧亚）", "约1710万 km²", "约1.44亿"],
    "Germany":        ["/ˈdʒɜːrməni/", "德国", "欧洲", "约35.7万 km²", "约8400万"],
    "France":         ["/fræns/", "法国", "欧洲", "约64.4万 km²（含海外）", "约6800万"],
    "United Kingdom": ["/juːˈnaɪtɪd ˈkɪŋdəm/", "英国", "欧洲", "约24.4万 km²", "约6800万"],
    "Italy":          ["/ˈɪtəli/", "意大利", "欧洲", "约30.1万 km²", "约5900万"],
    "Spain":          ["/speɪn/", "西班牙", "欧洲", "约50.6万 km²", "约4800万"],
    "United States":  ["/juːˈnaɪtɪd steɪts/", "美国", "北美洲", "约983万 km²", "约3.4亿"],
    "Canada":         ["/ˈkænədə/", "加拿大", "北美洲", "约998万 km²", "约4100万"],
    "Brazil":         ["/brəˈzɪl/", "巴西", "南美洲", "约851万 km²", "约2.17亿"],
    "Mexico":         ["/ˈmɛksɪkoʊ/", "墨西哥", "北美洲", "约196万 km²", "约1.29亿"],
    "Argentina":      ["/ˌɑːrdʒənˈtiːnə/", "阿根廷", "南美洲", "约278万 km²", "约4600万"],
    "Australia":      ["/ɔːˈstreɪliə/", "澳大利亚", "大洋洲", "约769万 km²", "约2700万"],
    "Egypt":          ["/ˈiːdʒɪpt/", "埃及", "非洲（西奈半岛属亚洲）", "约100万 km²", "约1.14亿"],
    "South Africa":   ["/ˌsaʊθ ˈæfrɪkə/", "南非", "非洲", "约122万 km²", "约6000万"],
    "Nigeria":        ["/naɪˈdʒɪəriə/", "尼日利亚", "非洲", "约92.4万 km²", "约2.33亿"],
    "Saudi Arabia":   ["/ˌsaʊdi əˈreɪbiə/", "沙特阿拉伯", "亚洲", "约215万 km²", "约3700万"],
}

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

# 3. 注入 CSS，去掉页面默认边距，实现真正全屏
c.add_js_funcs("var countryInfo = " + str(country_info).replace("'", '"') + ";")
c.add_js_funcs("""
    document.body.style.margin = '0';
    document.body.style.padding = '0';
    document.body.style.overflow = 'hidden';
""")

# 4. 生成文件
c.render("worldBlank.html")
print("世界地图已生成，请查看 worldBlank.html")
