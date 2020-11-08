/* Object creation */
[@bs.scope "L"] [@bs.new]
external createMarker:
  (~pos: LatLng.t, ~opts: option(Marker.options)=?, unit) => Marker.t =
  "marker";

/* Methods */
[@bs.send] external addMarkerToMap: (Marker.t, Map.t) => Marker.t = "addTo";

[@bs.send]
external removeMarkerFromMap: (Marker.t, Map.t) => Marker.t = "removeFrom";

[@bs.send]
external setMarkerLatLng: (Marker.t, LatLng.t) => Marker.t = "setLatLng";
