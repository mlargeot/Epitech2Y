import React from 'react'
import styled from 'styled-components';
import AdminButton from './AdminButton';
import logo from "../../../6tm.svg"
import { useState } from 'react';
import SearchBar from './SearchBar';

export default function HomePage() {
    const [searchResults, setSearchResults] = useState([]);
  
    const handleSearch = (query) => {
        setSearchResults(results);
    };
    return (
        <HomePageStyled>
            <nav>
                <div className="logo">
                    <img src={logo} alt="" />
                </div>
                <div>
                    <SearchBar onSearch={handleSearch} />
                    <ul>
                      {searchResults.map((result) => (
                        <li key={result.id}>{result.name}</li>
                      ))}
                    </ul>
                </div>
                <div className="buttonPart">
                    <AdminButton />
                </div>
            </nav>
        </HomePageStyled>
    )
}

const HomePageStyled = styled.div`
  width: 100%;
  height: 100vh;
  background: #a6a6a6;

  nav {
    width: 100%;
    height: 10vh;
    background: #5b5b5b;
    display: flex;
    justify-content: space-between;
    align-items: center;

    .logo {
        padding-left: 5%;
    }
    .buttonPart {
        padding-right: 5%;
        background-color:#5b5b5b;
    }
  }
`;
