[@react.component]
let make = (~marker: Marker.t, ~popupOptions: Popup.options, ~children) => {
  React.useEffect2(
    () => {
      PopupBinding.bindPopup(
        marker,
        ReactDOMServerRe.renderToString(children),
        ~opt=popupOptions,
        (),
      )
      |> ignore;
      None;
    },
    ([|marker|], children),
  );
  <> </>;
};
