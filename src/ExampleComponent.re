[@react.component]
let make = () =>
  <div>
    <MapCmp
      mapOptions={
        map_elem_id: "map_div",
        options: {
          center: {
            lat: 13.0,
            lng: 77.60,
          },
          zoom: 12,
        },
      }>
      {map =>
         <MarkerCmp
           map
           marker_props={
             location: {
               lat: 13.0,
               lng: 77.60,
             },
             marker_options: None,
           }>
           {(marker: Marker.t) => {
              <PopupCmp marker popupOptions={close_button: true}>
                {<div> {React.string("This is a popup")} </div>}
              </PopupCmp>;
            }}
         </MarkerCmp>}
    </MapCmp>
  </div>;
