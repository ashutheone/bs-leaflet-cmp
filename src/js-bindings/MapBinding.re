/* Object creation */
[@bs.scope "L"] [@bs.new]
external createMap: (string, Map.options) => Map.t = "map";

[@bs.scope "L"] [@bs.new]
external createTileLayer: (string, TileLayer.tileLayerOptions) => TileLayer.t =
  "tileLayer";

/* Methods */
[@bs.send]
external addLayerToMap: (TileLayer.t, Map.t) => TileLayer.t = "addTo";
