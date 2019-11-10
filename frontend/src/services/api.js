import axios from "axios";

const api = axios.create({
  baseURL: "http://192.168.43.7:80"
});

export default api;
