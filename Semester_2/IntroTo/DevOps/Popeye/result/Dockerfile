FROM node:12-alpine
USER root
WORKDIR /home/
COPY views /home/views
COPY package.json /home/
COPY server.js /home/
RUN npm install
EXPOSE 80
CMD [ "node", "server.js" ]