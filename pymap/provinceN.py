# 确保已安装：pip install pyecharts
from pyecharts.charts import Map
from pyecharts import options as opts
from pyecharts.commons.utils import JsCode

# 省份简称映射
abbr_map = {
    "湖南": "湘", "湖北": "鄂", "广东": "粤", "广西": "桂",
    "河南": "豫", "河北": "冀", "山东": "鲁", "山西": "晋",
    "四川": "川", "西藏": "藏", "云南": "云", "贵州": "黔",
    "内蒙古": "蒙", "吉林": "吉", "安徽": "皖",
    "北京": "京", "上海": "沪", "天津": "津", "重庆": "渝",
    "香港": "港", "澳门": "澳", "青海": "青", "甘肃": "甘", "陕西": "陕",
    "江苏": "苏", "浙江": "浙", "江西": "赣", "黑龙江": "黑", "新疆": "新",
    "辽宁": "辽", "宁夏": "宁", "福建": "闽", "海南": "琼", "台湾": "台"
}

# 1. 准备分组数据
group_1 = [
    ("湖南", 30), ("湖北", 30), ("广东", 30), ("广西", 30),
    ("河南", 30), ("河北", 30), ("山东", 30), ("山西", 30)
]

group_2 = [
    ("四川", 50), ("西藏", 50), ("云南", 50), ("贵州", 50),
    ("内蒙古", 50), ("吉林", 50), ("安徽", 50)
]

group_3 = [
    ("北京", 70), ("上海", 70), ("天津", 70), ("重庆", 70),
    ("香港", 70), ("澳门", 70), ("青海", 70), ("甘肃", 70), ("陕西", 70)
]

group_4 = [
    ("江苏", 90), ("浙江", 90), ("江西", 90), ("黑龙江", 90), ("新疆", 90),
    ("辽宁", 90), ("宁夏", 90), ("福建", 90), ("海南", 90), ("台湾", 90)
]

data = group_1 + group_2 + group_3 + group_4

# 34 个省级行政中心（红点）：名称、经度、纬度
capitals = [
    ("北京", 116.407, 39.904), ("天津", 117.201, 39.084),
    ("石家庄", 114.502, 38.045), ("太原", 112.549, 37.857),
    ("呼和浩特", 111.751, 40.842), ("沈阳", 123.429, 41.797),
    ("长春", 125.324, 43.887), ("哈尔滨", 126.642, 45.756),
    ("上海", 121.473, 31.230), ("南京", 118.797, 32.060),
    ("杭州", 120.155, 30.274), ("合肥", 117.283, 31.861),
    ("福州", 119.296, 26.075), ("南昌", 115.892, 28.676),
    ("济南", 117.121, 36.651), ("郑州", 113.625, 34.747),
    ("武汉", 114.305, 30.593), ("长沙", 112.939, 28.228),
    ("广州", 113.264, 23.129), ("南宁", 108.320, 22.824),
    ("海口", 110.331, 20.031), ("重庆", 106.551, 29.563),
    ("成都", 104.066, 30.573), ("贵阳", 106.630, 26.647),
    ("昆明", 102.833, 24.880), ("拉萨", 91.132, 29.660),
    ("西安", 108.948, 34.263), ("兰州", 103.834, 36.061),
    ("西宁", 101.778, 36.617), ("银川", 106.232, 38.486),
    ("乌鲁木齐", 87.617, 43.793), ("台北", 121.520, 25.030),
    ("香港", 114.171, 22.319), ("澳门", 113.543, 22.190),
]

capital_data = [
    {"name": n, "coord": [lng, lat]} for n, lng, lat in capitals
]

# 2. 创建全屏地图
c = (
    Map(init_opts=opts.InitOpts(width="100%", height="100vh", chart_id="cnmap"))
    .add(
        "",
        data,
        "china",
        label_opts=opts.LabelOpts(
            is_show=True,          # 显示"广东""宁夏"等短名，去掉省/市/自治区等后缀
            font_size=10,
            formatter=JsCode(
                "function(p){return p.name.replace("
                "/(特别行政区|壮族自治区|回族自治区|维吾尔自治区|自治区|省|市)$/,'');}"
            ),
        ),
    )
    .set_global_opts(
        visualmap_opts=opts.VisualMapOpts(is_show=False),
        tooltip_opts=opts.TooltipOpts(
            is_show=True,                              # 开启鼠标悬停提示框
            formatter=JsCode(
                "function(params) { "
                "var abbr = provinceAbbr[params.name] || ''; "
                "return params.name + (abbr ? '-' + abbr : ''); "
                "}"
            ),
        ),
    )
)

# 3. 向地图系列注入省会红点（markPoint）
c.options["series"][0]["markPoint"] = {
    "symbol": "circle",
    "symbolSize": 5,
    "silent": False,               # 红点响应鼠标，悬停显示省会名称
    "tooltip": {
        "show": True,
        "formatter": "{b}",   # {b} 为红点名称
    },
    "emphasis": {"scale": 1.5},    # 悬停时红点放大，方便鼠标命中
    "itemStyle": {"color": "#e53935"},
    "data": capital_data,
}

# 4. 注入CSS和省份简称JS字典
js_inject = (
    "var provinceAbbr = " + str(abbr_map).replace("'", '"') + ";"
    "document.body.style.margin = '0';"
    "document.body.style.padding = '0';"
    "document.body.style.overflow = 'hidden';"
)
c.add_js_funcs(js_inject)

# 4. 生成文件
c.render("provinceN.html")
print("地图已生成，请查看 provinceN.html")
