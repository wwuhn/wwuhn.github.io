import matplotlib.pyplot as plt
from mpl_toolkits.basemap import Basemap
from matplotlib.patches import Polygon


plt.figure(figsize=(16,8))
m = Basemap(
    llcrnrlon=77,
    llcrnrlat=14,
    urcrnrlon=140,
    urcrnrlat=51,
    projection='lcc',
    lat_1=33,
    lat_2=45,
    lon_0=100
)

m.drawcountries(linewidth=1.5)
m.drawcoastlines()


m.readshapefile('gadm36_CHN_shp/gadm36_CHN_1', 'states', drawbounds=True)
ax = plt.gca()
for nshape, seg in enumerate(m.states):
    poly = Polygon(seg, facecolor='r')
    ax.add_patch(poly)
# 加入台湾版图
m.readshapefile('gadm36_TWN_shp/gadm36_TWN_0', 'states', drawbounds=True)
for nshape, seg in enumerate(m.states):
    poly = Polygon(seg, facecolor='r')
    ax.add_patch(poly)
plt.show()
