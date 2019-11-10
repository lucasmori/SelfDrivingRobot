import React from "react";
import api from "../../services/api";
import "./styles.css";

export default function Homepage() {
  async function startSubmit() {
    console.log("iniciou");
    const response = await api.get("/run", {});
    console.log(response.data);
  }

  async function stopSubmit() {
    console.log("parou");
    const response = await api.get("/stop", {});
    console.log(response.data);
  }

  return (
    <div className="background">
      <div className="panel">
        <div className="panel-container">
          <div className="header-container">
            <div className="header">
              <h2>CONTROLE DE MOVIMENTO</h2>
            </div>
          </div>
          <div className="buttons-container">
            <button className="startButton" onClick={startSubmit}>
              INICIAR
            </button>
            <button className="stopButton" onClick={stopSubmit}>
              PARAR
            </button>
          </div>
        </div>
      </div>
    </div>
  );
}
