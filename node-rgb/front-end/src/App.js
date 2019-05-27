import React, { Component } from "react";
import { SketchPicker } from "react-color";
import axios from "axios";
import "./styles.css";

class App extends Component {
  state = {
    rgb: null,
    color: "#223"
  };
  sendArduino = () => {
    const { r, g, b } = this.state.rgb;
    axios.get(`http://11.1.1.117:9999/change/${r}/${g}/${b}`).then(result => {
      console.log(result);
    });
  };
  onChangeComplete = props => {
    this.setState({ rgb: props.rgb, color: props.hex });
    this.sendArduino();
  };
  render() {
    return (
      <div className="container">
        <h1>Selecione uma cor</h1>
        <SketchPicker
          className="picker"
          color={this.state.color}
          onChangeComplete={this.onChangeComplete}
        />
        <span>R: {this.state.rgb && this.state.rgb.r}</span>
        <span>G: {this.state.rgb && this.state.rgb.g}</span>
        <span>B: {this.state.rgb && this.state.rgb.b}</span>
      </div>
    );
  }
}

export default App;
