FROM python:3
USER root
WORKDIR /home/
COPY static /home/static
COPY templates /home/templates
COPY app.py /home/
COPY requirements.txt /home/
RUN pip3 install -r requirements.txt
EXPOSE 80
CMD [ "flask", "run", "--host=0.0.0.0", "--port=80" ]
