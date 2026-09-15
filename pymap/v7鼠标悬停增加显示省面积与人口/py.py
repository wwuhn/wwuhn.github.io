def create_china_map():
    html_content = r"""<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title>中国地图</title>
    <script src="https://cdn.jsdelivr.net/npm/echarts@4.9.0/dist/echarts.min.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/echarts@4.9.0/map/js/china.js"></script>
    <style>
        * { margin: 0; padding: 0; }
        #main { width: 100vw; height: 100vh; }
        #legend {
            position: absolute;
            left: 24px;
            top: 120px;
            z-index: 10;
            user-select: none;
        }
        .legend-item {
            font-size: 15px;
            font-weight: bold;
            line-height: 2.2;
            cursor: pointer;
            padding: 2px 8px;
            border-radius: 4px;
            transition: all 0.25s;
        }
        .legend-item:hover {
            background: rgba(0,0,0,0.06);
        }
        .legend-item.active {
            opacity: 0.35;
            text-decoration: line-through;
        }
    </style>
</head>
<body>
    <div id="main"></div>
    <div id="legend">
        <div class="legend-item" data-group="1" style="color:#2b88b9">两湖两广两河山</div>
        <div class="legend-item" data-group="2" style="color:#b8c418">川藏云贵蒙吉安</div>
        <div class="legend-item" data-group="3" style="color:#e8943a">四市二区青甘陕</div>
        <div class="legend-item" data-group="4" style="color:#df6a5d">五江二宁福海湾</div>
    </div>
    <script>
        var chart = echarts.init(document.getElementById('main'));

        // 省份详细信息：省会、面积（万km²）、人口（万人，2025年末）
        var provinceDetail = {
            '湖南':   {capital:'长沙',   area:'21.18', pop:'6492'},
            '湖北':   {capital:'武汉',   area:'18.59', pop:'5811'},
            '广东':   {capital:'广州',   area:'17.97', pop:'12859'},
            '广西':   {capital:'南宁',   area:'23.76', pop:'4989'},
            '河南':   {capital:'郑州',   area:'16.70', pop:'9744'},
            '河北':   {capital:'石家庄', area:'18.88', pop:'7354'},
            '山东':   {capital:'济南',   area:'15.79', pop:'10043'},
            '山西':   {capital:'太原',   area:'15.67', pop:'3424'},
            '四川':   {capital:'成都',   area:'48.60', pop:'8318'},
            '西藏':   {capital:'拉萨',   area:'122.84',pop:'374'},
            '云南':   {capital:'昆明',   area:'39.41', pop:'4644'},
            '贵州':   {capital:'贵阳',   area:'17.61', pop:'3857'},
            '内蒙古': {capital:'呼和浩特',area:'118.30',pop:'2374'},
            '吉林':   {capital:'长春',   area:'18.74', pop:'2297'},
            '安徽':   {capital:'合肥',   area:'14.01', pop:'6082'},
            '北京':   {capital:'北京',   area:'1.64',  pop:'2180'},
            '天津':   {capital:'天津',   area:'1.20',  pop:'1363'},
            '上海':   {capital:'上海',   area:'0.63',  pop:'2485'},
            '重庆':   {capital:'重庆',   area:'8.24',  pop:'3187'},
            '青海':   {capital:'西宁',   area:'72.23', pop:'592'},
            '甘肃':   {capital:'兰州',   area:'42.58', pop:'2443'},
            '陕西':   {capital:'西安',   area:'20.56', pop:'3936'},
            '江苏':   {capital:'南京',   area:'10.72', pop:'8518'},
            '江西':   {capital:'南昌',   area:'16.69', pop:'4474'},
            '浙江':   {capital:'杭州',   area:'10.55', pop:'6701'},
            '黑龙江': {capital:'哈尔滨', area:'47.30', pop:'3001'},
            '宁夏':   {capital:'银川',   area:'6.64',  pop:'732'},
            '新疆':   {capital:'乌鲁木齐',area:'166.00',pop:'2639'},
            '辽宁':   {capital:'沈阳',   area:'14.86', pop:'4131'},
            '福建':   {capital:'福州',   area:'12.40', pop:'4190'},
            '海南':   {capital:'海口',   area:'3.54',  pop:'1055'},
            '台湾':   {capital:'台北',   area:'3.60',  pop:'2340'}
        };

        var groupColors = {1:'#2b88b9', 2:'#b8c418', 3:'#e8943a', 4:'#df6a5d'};
        var groupState = {1:false, 2:false, 3:false, 4:false};

        var provinceInfo = [
            {name:'湖南',group:1},{name:'湖北',group:1},{name:'广东',group:1},{name:'广西',group:1},
            {name:'河南',group:1},{name:'河北',group:1},{name:'山东',group:1},{name:'山西',group:1},
            {name:'四川',group:2},{name:'西藏',group:2},{name:'云南',group:2},{name:'贵州',group:2},
            {name:'内蒙古',group:2},{name:'吉林',group:2},{name:'安徽',group:2},
            {name:'北京',group:3},{name:'天津',group:3},{name:'上海',group:3},{name:'重庆',group:3},
            {name:'青海',group:3},{name:'甘肃',group:3},{name:'陕西',group:3},
            {name:'江苏',group:4},{name:'江西',group:4},{name:'浙江',group:4},{name:'黑龙江',group:4},
            {name:'宁夏',group:4},{name:'新疆',group:4},
            {name:'辽宁',group:4},{name:'福建',group:4},{name:'海南',group:4},{name:'台湾',group:4}
        ];

        function getDisplayData() {
            return provinceInfo.map(function(p) {
                if (groupState[p.group]) {
                    return {name:p.name, value:0, itemStyle:{areaColor:'#ffffff', borderColor:'#ccc'}};
                }
                return {name:p.name, value:p.group * 25};
            });
        }

        var option = {
            title: {
                text: '中国地图',
                left: 20,
                top: 20,
                textStyle: { fontSize: 20, fontWeight: 'bold' }
            },
            tooltip: {
                trigger: 'item',
                formatter: function(params) {
                    var name = params.name;
                    var info = provinceDetail[name];
                    if (!info) return name;
                    return '<b style="font-size:15px">' + name + '</b>'
                        + '<br/>省会：' + info.capital
                        + '<br/>面积：' + info.area + ' 万km²'
                        + '<br/>人口：' + info.pop + ' 万人';
                },
                extraCssText: 'line-height:1.8;'
            },
            toolbox: {
                show: true,
                right: 20,
                top: 'center',
                orient: 'vertical',
                feature: {
                    saveAsImage: { show: true, title: '保存为图片' },
                    restore: { show: true, title: '重置' },
                    dataView: { show: true, title: '数据视图' }
                }
            },
            visualMap: {
                type: 'continuous',
                min: 0,
                max: 100,
                left: 20,
                bottom: 40,
                text: ['高', '低'],
                calculable: true,
                inRange: {
                    color: ['#2b88b9', '#b8c418', '#e8943a', '#df6a5d']
                },
                outOfRange: {
                    color: '#ffffff'
                }
            },
            series: [{
                name: '省份',
                type: 'map',
                mapType: 'china',
                roam: true,
                label: {
                    show: true,
                    fontSize: 11,
                    color: '#000'
                },
                itemStyle: {
                    areaColor: '#e0e0e0',
                    borderColor: '#888'
                },
                emphasis: {
                    label: { show: true, fontSize: 13, fontWeight: 'bold' },
                    itemStyle: {
                        areaColor: '#f5f5f5',
                        borderColor: '#333'
                    }
                },
                data: getDisplayData(),
                markPoint: {
                    symbol: 'circle',
                    symbolSize: 6,
                    itemStyle: { color: '#d93a3a' },
                    label: { show: false },
                    data: [
                        {name:'长沙',coord:[112.94,28.23]},
                        {name:'武汉',coord:[114.31,30.59]},
                        {name:'广州',coord:[113.26,23.13]},
                        {name:'南宁',coord:[108.32,22.82]},
                        {name:'郑州',coord:[113.65,34.76]},
                        {name:'石家庄',coord:[114.48,38.03]},
                        {name:'济南',coord:[117.00,36.65]},
                        {name:'太原',coord:[112.55,37.87]},
                        {name:'成都',coord:[104.07,30.67]},
                        {name:'拉萨',coord:[91.13,29.66]},
                        {name:'昆明',coord:[102.73,25.04]},
                        {name:'贵阳',coord:[106.71,26.57]},
                        {name:'呼和浩特',coord:[111.65,40.82]},
                        {name:'长春',coord:[125.35,43.88]},
                        {name:'合肥',coord:[117.27,31.86]},
                        {name:'北京',coord:[116.46,39.92]},
                        {name:'天津',coord:[117.20,39.13]},
                        {name:'上海',coord:[121.48,31.22]},
                        {name:'重庆',coord:[106.54,29.59]},
                        {name:'银川',coord:[106.27,38.47]},
                        {name:'乌鲁木齐',coord:[87.68,43.77]},
                        {name:'西宁',coord:[101.74,36.56]},
                        {name:'兰州',coord:[103.83,36.06]},
                        {name:'西安',coord:[108.95,34.27]},
                        {name:'南京',coord:[118.78,32.04]},
                        {name:'南昌',coord:[115.89,28.68]},
                        {name:'杭州',coord:[120.19,30.26]},
                        {name:'哈尔滨',coord:[126.63,45.75]},
                        {name:'沈阳',coord:[123.38,41.80]},
                        {name:'福州',coord:[119.30,26.08]},
                        {name:'海口',coord:[110.35,20.02]},
                        {name:'台北',coord:[121.50,25.03]}
                    ]
                }
            }]
        };

        chart.setOption(option);

        var legendItems = document.querySelectorAll('.legend-item');
        legendItems.forEach(function(item) {
            item.addEventListener('click', function() {
                var group = parseInt(this.getAttribute('data-group'));
                groupState[group] = !groupState[group];
                this.classList.toggle('active');
                chart.setOption({
                    series: [{ data: getDisplayData() }]
                });
            });
        });

        window.addEventListener('resize', function() { chart.resize(); });
    </script>
</body>
</html>"""

    with open("render.html", "w", encoding="utf-8") as f:
        f.write(html_content)
    print("生成成功！请在同目录下打开 render.html 查看效果。")

if __name__ == "__main__":
    create_china_map()
