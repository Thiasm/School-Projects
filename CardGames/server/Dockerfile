FROM node:12
WORKDIR /server
COPY package-lock.json /server
COPY package.json /server
RUN npm install
COPY . /server
EXPOSE 8080
CMD [ "node", "server.js" ]