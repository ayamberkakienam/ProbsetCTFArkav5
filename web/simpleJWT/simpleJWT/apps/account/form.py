from django import forms

from django.contrib.auth.models import User

class LoginForm(forms.Form):
    username = forms.RegexField(
        label='Username',
        max_length=30,
        regex=r'^[\w-]+$',
    )
    password = forms.CharField(widget=forms.PasswordInput)

class RegistrationForm(forms.ModelForm):
    username = forms.RegexField(
        label='Username',
        max_length=30,
        regex=r'^[\w-]+$',
    )
    password = forms.CharField(widget=forms.PasswordInput)
    class Meta:
        model = User
        fields = ('username', 'password',)