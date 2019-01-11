from django.shortcuts import render, redirect
from simpleJWT.apps.account.form import RegistrationForm, LoginForm
from django.contrib.auth import authenticate
from django.contrib.auth.models import User
from simpleJWT.settings import SECRET_KEY
from django.http import HttpResponse
import jwt
# Create your views here.


def index(request):
    if 'session' in request.COOKIES:
        header = jwt.get_unverified_header(request.COOKIES['session'])
        if header['alg'] == 'none':
            payload = jwt.decode(request.COOKIES['session'], verify=False)
        else:
            payload = jwt.decode(request.COOKIES['session'], SECRET_KEY)
        print(payload)
        if 'is_admin' in payload and payload['is_admin'] == True:
            return render(request, 'flag.html')
    return render(request,'index.html')

def register(request):
    if 'session' in request.COOKIES:
        response = redirect('index')
        return response
    if request.method == "POST":
        form = RegistrationForm(request.POST)
        if form.is_valid():
            if not User.objects.filter(email = form.cleaned_data['username']).exists():
                user = User.objects.create_user(form.cleaned_data['username'], 'aa@aa.com', form.cleaned_data['password'])
                payload = jwt.encode({'is_admin':False, 'username':user.username},SECRET_KEY, algorithm='HS256').decode('utf-8')
                response = redirect('index')
                response.set_cookie('session',payload)
                return response
            else:
                return HttpResponse("User already exist")


    form = RegistrationForm()
    return render(request, 'registration.html', {'form': form})

def login(request):
    if 'session' in request.COOKIES:
        response = redirect('index')
        return response
    if request.method == "POST":
        form = LoginForm(request.POST)
        if form.is_valid():
            user = authenticate(username=form.cleaned_data['username'], password=form.cleaned_data['password'])
            if user is not None:
                payload = jwt.encode({'is_admin':False, 'username':form.cleaned_data['username']},SECRET_KEY, algorithm='HS256').decode('utf-8')
                response = redirect('index')
                response.set_cookie('session',payload)
                return response
            else:
                return HttpResponse("Login failed")

    form = LoginForm()
    return render(request, 'login.html', {'form': form})

def logout(request):
    response = redirect('index')
    response.delete_cookie('session')
    return response