from flask import Flask, render_template, request
from datetime import datetime


app = Flask(__name__)


@app.get('/')
def route_index():
    print('route_index')
    now = datetime.now()
    return render_template('index.jinja', now=now)


@app.get('/login')
def route_login():
    print('route_login')
    now = datetime.now()
    return render_template('login.jinja', now=now)


@app.post('/login')
def route_index_post():
    print('route_login_post')
    now = datetime.now()
    print(request.form)
    username = request.form['uname']
    return render_template('after.jinja', now=now, username=username)


def main():
    app.run(host='0.0.0.0', port=5000)


if __name__ == '__main__':
    main()
