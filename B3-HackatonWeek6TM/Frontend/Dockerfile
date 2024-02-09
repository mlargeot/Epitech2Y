# Utilisez l'image officielle de Node.js
FROM node:latest

# Définissez le répertoire de travail dans le conteneur
WORKDIR /app

# Copiez les fichiers du frontend dans le conteneur
COPY . .

# Installez les dépendances
RUN npm install

# Exposez le port sur lequel l'application va écouter
EXPOSE 5173

# Commande pour exécuter l'application lors du démarrage du conteneur
CMD ["npm", "run", "dev"]
