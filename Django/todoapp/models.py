from django.db import models
from django.conf import settings
from django.utils import timezone
from django import forms
import datetime

# Create your models here.

class todo(models.Model):
    # now = datetime.now().strftime("%d-%m-%Y")
    # date_time_str = datetime.strptime(now, '%d-%m-%y')
    
    itemId = models.AutoField(primary_key=True)
    title = models.CharField(max_length=200)
    description = models.TextField()
    status = models.BooleanField(default=False)
    created_date = models.DateTimeField(default=timezone.now())
    targeted_date = models.DateTimeField(default=timezone.now())

    def publish(self):
        self.targeted_date = timezone.now()
        self.save()

    def __str__(self):
        return self.title


	
