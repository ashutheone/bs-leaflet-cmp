type state = {marker: option(Marker.t)};

type actions =
  | SetMyMarker(option(Marker.t));

let reducer = (_state: state, action: actions) => {
  switch (action) {
  | SetMyMarker(marker) => {marker: marker}
  };
};

[@react.component]
let make = (~map: Map.t, ~marker_props: Marker.markerProps, ~children) => {
  let initialState = {marker: None};
  let (state, dispatch) = React.useReducer(reducer, initialState);

  React.useEffect0(() => {
    let marker =
      MarkerBinding.createMarker(
        ~pos=marker_props.location,
        ~opts=marker_props.marker_options,
        (),
      );
    MarkerBinding.addMarkerToMap(marker, map) |> ignore;
    dispatch(SetMyMarker(Some(marker)));
    Some(() => MarkerBinding.removeMarkerFromMap(marker, map)->ignore);
  });
  React.useEffect1(
    () => {
      switch (state.marker) {
      | Some(marker) =>
        MarkerBinding.setMarkerLatLng(marker, marker_props.location) |> ignore
      | _ => ()
      };
      None;
    },
    [|marker_props.location|],
  );
  <>
    {switch (state.marker) {
     | Some(marker) => children(marker)
     | None => React.null
     }}
  </>;
};
