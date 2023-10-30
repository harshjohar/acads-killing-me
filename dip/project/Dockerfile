FROM python:3.5

WORKDIR /

COPY requirements.txt ./
RUN pip install --no-cache-dir -r requirements.txt

COPY . .

CMD [ "./src/code/" ]