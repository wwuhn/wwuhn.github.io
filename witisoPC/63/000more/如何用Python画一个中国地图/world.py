import matplotlib.pyplot as pit
from mpl_toolkits.basemap import Basemap

pit.figure(figsize=(16,8))
m = Basemap()
m.drawcoastlines()
m.drawcountries(linewidth=1.5)
#m= Basemap(llcrnrlon=73, llcrnrlat=18, urcrnrlon=135, urcrnrlat=53)
#m= Basemap(llcrnrlon=77, llcrnrlat=14, urcrnrlon=140, urcrnrlat=51, projection='lcc', lat_1=33, lat_2=45, lon_0=100)
pit.show()
"""
from matplotlib.patches import Polygon
ax = pit.gca()
for nshape, seg in enumerate(m.cstates):
    poly = Polygon(seg, facecolor='r')
    ax.add_patch(poly)

"""
