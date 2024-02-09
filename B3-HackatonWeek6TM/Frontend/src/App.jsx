import { BrowserRouter, Routes, Route } from "react-router-dom"
import './App.css'
import HomePage from "./components/pages/HomePage/HomePage"
import { LoginPage } from "./components/pages/HomePage/LoginPage"

function App() {
  return (
    <BrowserRouter>
      <Routes>
      <Route path="/" element={<HomePage />} />
      <Route path="/admin" element={<LoginPage />} />
      </Routes>
    </BrowserRouter>
  )
}

export default App
