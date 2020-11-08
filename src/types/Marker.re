type t;
type icon;
type options = {
  icon,
  title: option(string),
  zIndexOffset: option(int),
  riseOnHover: option(bool),
  riseOffset: option(int),
};
type markerProps = {
  location: LatLng.t,
  marker_options: option(options),
};
