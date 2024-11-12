FROM node:12
WORKDIR /dashboard
COPY package-lock.json /dashboard
COPY package.json /dashboard
RUN npm install
RUN npm i -g @angular/cli
COPY . /dashboard
EXPOSE 4200
CMD [ "ng", "serve", "--host", "0.0.0.0", "--port", "4200"]