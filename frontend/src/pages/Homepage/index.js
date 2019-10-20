import React, { useState } from 'react';
import api from '../../services/api';

export default function Homepage() {

  async function startSubmit() {
    console.log("iniciou");
    const response = await api.get('/run', {});
    console.log(response.data);
  }

  async function stopSubmit() {
    console.log("parou");
    const response = await api.get('/stop', {});
    console.log(response.data);
  }

  return (
    <>
      <div className="form">
        <h1>Self Driving Robot</h1>
        <label>Control Movement</label>
        <button className="btn start" onClick={startSubmit}>Start</button>
        <button className="btn" onClick={stopSubmit}>Stop</button>
        </div>
    </>
  )
}