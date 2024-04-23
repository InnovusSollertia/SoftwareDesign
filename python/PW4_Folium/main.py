import folium
objectPlace = folium.Map(location=(43.2567, 76.9286))
objectPlace.save("ProjectScience/software/python/PW4/almaty.html")

group_1 = folium.FeatureGroup("first group").add_to(objectPlace)
folium.Marker((43.128246, 76.906423), icon=folium.Icon("red")).add_to(group_1)
folium.Marker((43.193288, 76.888203), icon=folium.Icon("red")).add_to(group_1)

group_2 = folium.FeatureGroup("second group").add_to(objectPlace)
folium.Marker((43.162086, 77.040838), icon=folium.Icon("green")).add_to(group_2)

folium.LayerControl().add_to(objectPlace)