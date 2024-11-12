FROM node:12

WORKDIR /usr/src/app
COPY package*.json ./

RUN npm install
RUN npm install -g serve
COPY . .

RUN mkdir -p /mobile_app/
RUN ln -s /mobile_app/client.apk public/client.apk

EXPOSE 5000
CMD [ "npm", "run", "start-prod"]