FROM golang:1.11-alpine AS builder

ENV GO111MODULE=on

RUN apk add --no-cache git

WORKDIR /src
COPY go.mod go.sum ./
RUN go mod download

COPY . .
RUN CGO_ENABLED=0 GOOS=linux GOARCH=amd64 go build -a -installsuffix 'static' -ldflags="-w -s" -o /app/web ./app/web/main.go

FROM scratch as final

WORKDIR /app
COPY --from=builder /app/ ./

CMD ["/app/web"]
