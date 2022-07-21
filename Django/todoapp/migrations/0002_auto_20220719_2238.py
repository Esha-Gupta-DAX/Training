# Generated by Django 3.2.14 on 2022-07-19 17:08

import datetime
from django.db import migrations, models
from django.utils.timezone import utc


class Migration(migrations.Migration):

    dependencies = [
        ('todoapp', '0001_initial'),
    ]

    operations = [
        migrations.AlterField(
            model_name='todo',
            name='created_date',
            field=models.DateTimeField(default=datetime.datetime(2022, 7, 19, 17, 8, 10, 467613, tzinfo=utc)),
        ),
        migrations.AlterField(
            model_name='todo',
            name='targeted_date',
            field=models.DateTimeField(default=datetime.datetime(2022, 7, 19, 17, 8, 10, 467613, tzinfo=utc)),
        ),
    ]
