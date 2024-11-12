FROM cirrusci/flutter:1.22.6

COPY . /app
WORKDIR /app

RUN flutter pub get
RUN flutter clean
RUN flutter build apk

RUN mkdir /mobile_app/
RUN cp build/app/outputs/apk/release/app-release.apk /mobile_app/client.apk