# 确保已安装：pip install pyecharts
from pyecharts.charts import Map
from pyecharts import options as opts
from pyecharts.commons.utils import JsCode
from pyecharts.globals import CurrentConfig

# 资源本地化：生成的 HTML 引用同目录 assets/ 下的 echarts 与中国地图库，
# 不依赖外网 CDN，离线也能正常渲染。
CurrentConfig.ONLINE_HOST = "assets/"

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

# 简称 -> 地图数据中的全称（geo 区域匹配用全称）
full_map = {
    "北京": "北京市", "天津": "天津市", "河北": "河北省", "山西": "山西省",
    "内蒙古": "内蒙古自治区", "辽宁": "辽宁省", "吉林": "吉林省",
    "黑龙江": "黑龙江省", "上海": "上海市", "江苏": "江苏省", "浙江": "浙江省",
    "安徽": "安徽省", "福建": "福建省", "江西": "江西省", "山东": "山东省",
    "河南": "河南省", "湖北": "湖北省", "湖南": "湖南省", "广东": "广东省",
    "广西": "广西壮族自治区", "海南": "海南省", "重庆": "重庆市",
    "四川": "四川省", "贵州": "贵州省", "云南": "云南省",
    "西藏": "西藏自治区", "陕西": "陕西省", "甘肃": "甘肃省",
    "青海": "青海省", "宁夏": "宁夏回族自治区",
    "新疆": "新疆维吾尔自治区", "台湾": "台湾省",
    "香港": "香港特别行政区", "澳门": "澳门特别行政区",
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

# 分组填色（对应原 visualMap 连续渐变在 30/50/70/90 处的取值）
# group_colors = {30: "#acb986", 50: "#eac763", 70: "#e39761", 90: "#dd675e"}
group_colors = {30: "#cccccc", 50: "#cccccc", 70: "#cccccc", 90: "#cccccc"}


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

# 五岳（橙色圆点，悬停放大）：名称、经度、纬度
wuyue = [
    ("东岳泰山", 117.10, 36.25),
    ("西岳华山", 110.09, 34.49),
    ("南岳衡山", 112.73, 27.27),
    ("北岳恒山", 113.73, 39.66),
    ("中岳嵩山", 113.03, 34.51),
]

wuyue_data = [
    {
        "name": n,
        "coord": [lng, lat],
        "symbolSize": 12,
        "itemStyle": {"color": "#ef6c00", "borderColor": "#ffffff", "borderWidth": 1},
        "label": {
            "show": True,
            "formatter": "{b}",
            "position": "top",
            "color": "#bf360c",
            "fontSize": 12,
            "fontWeight": "bold",
        },
    }
    for n, lng, lat in wuyue
]

# 四渎水系曲线（简化干流 waypoints）：名称、颜色、经纬度折线点
sidu_lines = [
    ("长江", "#1e88e5", [
        [92.4, 33.0], [95.5, 32.2], [97.2, 33.0], [99.4, 30.5],
        [100.1, 26.9], [102.6, 27.5], [104.6, 28.8], [106.5, 29.6],
        [109.0, 30.6], [111.3, 30.7], [114.3, 30.6], [116.1, 29.7],
        [117.1, 30.5], [118.4, 31.3], [118.8, 32.0], [120.5, 31.9],
        [121.9, 31.4],
    ]),
    ("黄河", "#f9a825", [
        [96.4, 35.1], [100.9, 34.8], [102.5, 34.5], [103.8, 36.0],
        [105.5, 36.5], [106.8, 37.8], [107.6, 40.5], [110.4, 40.0],
        [111.0, 39.0], [110.5, 37.0], [110.4, 35.5], [110.5, 34.6],
        [112.2, 34.8], [113.7, 34.5], [115.0, 35.5], [116.5, 36.4],
        [117.6, 37.0], [118.6, 38.1],
    ]),
    ("淮河", "#00897b", [
        [112.9, 32.4], [114.4, 32.2], [115.8, 32.9], [117.35, 32.9],
        [118.6, 33.4], [119.6, 33.9], [120.3, 34.3],
    ]),
    ("济水", "#8e24aa", [
        [112.6, 35.1], [114.0, 35.4], [115.5, 35.3], [116.5, 35.6],
        [117.3, 36.2], [118.1, 37.0], [118.9, 37.6],
    ]),
]

SHORTEN = JsCode(
    "function(p){return p.name.replace("
    "/(特别行政区|壮族自治区|回族自治区|维吾尔自治区|自治区|省|市)$/,'');}"
)

# 悬停提示：全称去掉后缀再查简称，如 "湖南省-湘"
GEO_TIP = JsCode(
    "function(params) { "
    "var s = params.name.replace("
    "/(特别行政区|壮族自治区|回族自治区|维吾尔自治区|自治区|省|市)$/,''); "
    "var abbr = provinceAbbr[s] || ''; "
    "return params.name + (abbr ? '-' + abbr : ''); "
    "}"
)

# 2. 创建全屏地图
c = (
    Map(init_opts=opts.InitOpts(width="100%", height="100vh", chart_id="cnmap"))
    .add(
        "",
        [(full_map[n], v) for n, v in data],
        "china",
        label_opts=opts.LabelOpts(is_show=False),
    )
    .set_global_opts(
        visualmap_opts=opts.VisualMapOpts(is_show=False),
        tooltip_opts=opts.TooltipOpts(is_show=True),
    )
)

# 3. visualMap 限定只作用于省份填色系列
c.options["visualMap"] = {
    "show": False, "type": "continuous", "seriesIndex": [0],
    "min": 0, "max": 100,
    #"inRange": {"color": ["#50a3ba", "#eac763", "#d94e5d"]},
    "inRange": {"color": ["#fff", "#fff", "#fff"]},
}

# 4. geo 作为统一坐标系与可见底图：
#    负责缩放平移；省份分组填色用全称写入 regions；
#    四渎曲线(lines)与标注点共用同一坐标系、随地图同步缩放。
c.options["geo"] = [{
    "map": "china",
    "roam": True,
    "zoom": 1.15,
    "itemStyle": {"areaColor": "#eef2f7", "borderColor": "#b0b7c3"},
    "label": {"show": True, "formatter": SHORTEN, "fontSize": 10, "color": "#555"},
    "emphasis": {"itemStyle": {"areaColor": "#dbe4f0"}, "label": {"show": True}},
    "select": {"disabled": True},
    "tooltip": {"show": True, "formatter": GEO_TIP},
    "regions": [
        {"name": full_map[n], "itemStyle": {"areaColor": group_colors[v]}}
        for n, v in data
    ],
}]

# 5. 省份系列绑定 geo，缩放平移交给 geo 组件
s0 = c.options["series"][0]
s0["geoIndex"] = 0
s0["roam"] = False

# 6. 省会红点与五岳橙点（markPoint，随地图缩放，悬停放大）
s0["markPoint"] = {
    "symbol": "circle",
    "symbolSize": 5,
    "silent": False,               # 圆点响应鼠标，悬停显示名称
    "tooltip": {
        "show": True,
        "formatter": "{b}",        # {b} 为圆点名称
    },
    "emphasis": {"scale": 1.5},    # 悬停时圆点放大
    "itemStyle": {"color": "#e53935"},
    "data": capital_data + wuyue_data,
}

# 7. 四渎：每条水系一个 lines 曲线系列，末端标水系名
for name, color, coords in sidu_lines:
    c.options["series"].append({
        "type": "lines",
        "name": name,
        "coordinateSystem": "geo",
        "polyline": True,
        "silent": True,            # 细线不拦截鼠标
        "zlevel": 1,
        "z": 5,
        "data": [{"name": name, "coords": coords}],
        "lineStyle": {"color": color, "width": 2.5, "opacity": 0.95},
        "label": {
            "show": True,
            "position": "end",
            "formatter": "{b}",
            "color": color,
            "fontSize": 12,
            "fontWeight": "bold",
        },
    })

# 8. 注入CSS和省份简称JS字典
js_inject = (
    "var provinceAbbr = " + str(abbr_map).replace("'", '"') + ";"
    "document.body.style.margin = '0';"
    "document.body.style.padding = '0';"
    "document.body.style.overflow = 'hidden';"
)
c.add_js_funcs(js_inject)

# 9. 生成文件
c.render("cnBlank.html")
print("地图已生成，请查看 cnBlank.html")
