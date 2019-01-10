from django.shortcuts import render, redirect
from simpleJWT.apps.account.form import RegistrationForm, LoginForm
# Create your views here.

def index(request):
    if 'tehee' in request.COOKIES:
        return render(request, 'flag.html')
    return render(request,'index.html')

def register(request):
    if request.method == "POST":
        form = RegistrationForm(request.POST)
        if form.is_valid():
            form.save()
            response = redirect('index')
            response.set_cookie('tehee','123')
            return response

    form = RegistrationForm()
    return render(request, 'registration.html', {'form': form})

def login(request):
    if request.method == "POST":
        form = LoginForm(request.POST)
        if form.is_valid():
            form.save()
            response = redirect('index')
            response.set_cookie('tehee', '123')
            return response

    form = LoginForm()
    return render(request, 'login.html', {'form': form})
