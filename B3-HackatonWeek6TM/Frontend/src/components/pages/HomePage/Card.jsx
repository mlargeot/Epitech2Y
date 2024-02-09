import React, { useEffect, useState } from 'react';
import defaultImage from '../../../assets/default.jpg';

const Card = () => {
    const [data, setData] = useState([]);
    const [flip, setFlip] = useState([]);

    useEffect(() => {
        fetch('http://localhost:8000/workers')
            .then(response => response.json())
            .then(data => {
                setData(data);
                setFlip(new Array(data.length).fill(false));
            });
    }, []);

    const handleClick = index => {
        const newFlip = [...flip];
        newFlip[index] = !newFlip[index];
        setFlip(newFlip);
    };

    return (
        <div className="grid">
            {data.map((item, index) => (
                <div className={`card ${flip[index] ? 'flip' : ''}`} key={index} onClick={() => handleClick(index)}>
                    <div className="flip-card-inner">
                        <div className="flip-card-front">
                            <img
                                src={item.Photo_Pro || defaultImage}
                                alt={`${item.Prenom} ${item.Nom}`}
                                onMouseOver={e => (e.currentTarget.src = item.Photo_Fun || defaultImage)}
                                onMouseOut={e => (e.currentTarget.src = item.Photo_Pro || defaultImage)}
                            />
                            <div className="container">
                                <h4><b>{`${item.Prenom} ${item.Nom}`}</b></h4>
                            </div>
                        </div>
                        <div className="flip-card-back">
                            <div className="container">
                                <p>{`Nom: ${item.Nom}`}</p>
                                <p>{`Prenom: ${item.Prenom}`}</p>
                                <p>{`Poste: ${item.Poste}`}</p>
                                <p>{`Equipe: ${item.Equipe}`}</p>
                                <p>{`Agence: ${item.Agence}`}</p>
                            </div>
                        </div>
                    </div>
                </div>
            ))}
        </div>
    );
};

export default Card;
