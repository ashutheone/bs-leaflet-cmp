// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Caml_option = require("bs-platform/lib/js/caml_option.js");

function reducer(_state, action) {
  return {
          map_obj: action[0]
        };
}

function MapCmp(Props) {
  var mapOptions = Props.mapOptions;
  var children = Props.children;
  var centerLoc = mapOptions.options.center;
  var mapOpts_zoom = mapOptions.options.zoom;
  var mapOpts = {
    center: centerLoc,
    zoom: mapOpts_zoom
  };
  var match = React.useReducer(reducer, {
        map_obj: undefined
      });
  var dispatch = match[1];
  React.useEffect((function () {
          var mapObj = new (L.map)(mapOptions.map_elem_id, mapOpts);
          var tileLayer = new (L.tileLayer)("https://tile.thunderforest.com/neighbourhood/{z}/{x}/{y}.png?apikey=<YourApiKey>", {
                attribution: "Maps &copy; <a href='https://www.thunderforest.com/'>Thunderforest</a>, Data &copy; <a href='http://www.openstreetmap.org/copyright'>OpenStreetMap contributors</a>",
                minZoom: 11,
                maxZoom: 15
              });
          tileLayer.addTo(mapObj);
          Curry._1(dispatch, /* SetMyMap */[Caml_option.some(mapObj)]);
          
        }), ([]));
  var map = match[0].map_obj;
  return React.createElement(React.Fragment, undefined, React.createElement("div", {
                  className: "track-order-map__container"
                }, React.createElement("div", {
                      ref: React.useRef(null),
                      className: "track-order-map__canvas",
                      id: mapOptions.map_elem_id,
                      style: {
                        height: "400px",
                        width: "600px"
                      }
                    })), map !== undefined ? Curry._1(children, Caml_option.valFromOption(map)) : null, React.createElement("div", undefined));
}

var make = MapCmp;

exports.reducer = reducer;
exports.make = make;
/* react Not a pure module */