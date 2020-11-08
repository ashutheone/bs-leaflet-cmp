type state = {map_obj: option(Map.t)};

type actions =
  | SetMyMap(option(Map.t));

let reducer = (_state: state, action: actions) => {
  switch (action) {
  | SetMyMap(map) => {map_obj: map}
  };
};

[@react.component]
let make = (~mapOptions: Map.mapOptions, ~children: _ => React.element) => {
  let initialState = {map_obj: None};
  let centerLoc = mapOptions.options.center;
  let mapOpts: Map.options = {
    center: centerLoc,
    zoom: mapOptions.options.zoom,
  };

  let (state, dispatch) = React.useReducer(reducer, initialState);

  React.useEffect0(() => {
    let mapObj = MapBinding.createMap(mapOptions.map_elem_id, mapOpts);
    let tileLayer =
      MapBinding.createTileLayer(
        "https://tile.thunderforest.com/neighbourhood/{z}/{x}/{y}.png?apikey=<YourApiKey>",
        {
          attribution: "Maps &copy; <a href='https://www.thunderforest.com/'>Thunderforest</a>, Data &copy; <a href='http://www.openstreetmap.org/copyright'>OpenStreetMap contributors</a>",
          minZoom: 11,
          maxZoom: 15,
        },
      );
    MapBinding.addLayerToMap(tileLayer, mapObj)->ignore;
    dispatch(SetMyMap(Some(mapObj)));
    None;
  });
  <>
    <div className="track-order-map__container">
      <div
        id={mapOptions.map_elem_id}
        style={ReactDOM.Style.make(~height="400px", ~width="600px", ())}
        className="track-order-map__canvas"
        ref={ReactDOMRe.Ref.domRef(React.useRef(Js.Nullable.null))}
      />
    </div>
    {switch (state.map_obj) {
     | Some(map) => children(map)
     | None => React.null
     }}
    <div />
  </>;
};
