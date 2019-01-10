from django import forms

from django.contrib.auth.models import User

class LoginForm(forms.ModelForm):
    username = forms.RegexField(
        label='Username',
        max_length=30,
        regex=r'^[\w-]+$',
    )

    class Meta:
        model = User
        fields = ('username', 'password',)

class RegistrationForm(forms.ModelForm):
    username = forms.RegexField(
        label='Username',
        max_length=30,
        regex=r'^[\w-]+$',
    )
    class Meta:
        model = User
        fields = ('username', 'email', 'password',)